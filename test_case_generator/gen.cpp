#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define sz(x) (ll)x.size()

typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

// ------------------------------- RANDOM GENERATOR TEMPLATE -------------------------------

//Antreas Leonidou | 03-01-2023

class RandomGenerator{
private:
	static const ll N = 200000;
	mt19937 rng;

	void applyTreeIndexOffset(vii &edges, ll index_offset){
		for (ll i = 0; i<sz(edges); i++){
			edges[i].F += index_offset;
			edges[i].S += index_offset;
		}
	}

public:
	RandomGenerator(){
		rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
	}

	//------VALUES------

	ll getNum(ll l, ll r){	// l<=x<=r
		if (l > r){ cout<<endl<<"ERROR: RandomGenerator.genNum: Invalid Input (l: "<<l<<" r:"<<r<<")"<<endl; return LLONG_MIN;};
		return ((rng() % (abs(r-l)+1)) + l);
	}

	//------ARRAYS------

	vi getArr(ll n, ll l, ll r){
		if (l > r || n < 0 || n > N) { cout<<"ERROR: RandomGenerator.genArr: Invalid Input (n:"<<n<<" l:"<<l<<" r:"<<r<<")"<<endl; return vi();}
		vi ans(n);
		for (ll i =0; i<n; i++)
			ans[i] = getNum(l,r);
		return ans;
	}

	vi getPermutation(ll n, ll index_offset = 0){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getPermutation: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vi();}
		vi v(n);
		for (ll i=0; i<n; i++) v[i] = i + index_offset;
		shuffle(v.begin(), v.end(), rng);
		return v;
	}

	//------TREES------

	vii getTreeRandom(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeRandom: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i=1; i<n; i++){
			edges[i-1] = ii(getNum(0, i-1), i);
		}
		shuffle(edges.begin(), edges.end(), rng);
		vi randPerm = getPermutation(n);
		for (ll i =0; i<n-1; i++){
			if (getNum(0,1)) swap(edges[i].F, edges[i].S);
			edges[i] = ii(randPerm[edges[i].F], randPerm[edges[i].S]);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeBinary(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeBinary: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii((i-1)/2, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeLine(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeLine: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii(i-1, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeStar(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeStar: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii(0, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeAny(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeAny: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		ll type = getNum(0, 7);
		vii edges;
		switch (type){		//Random:62.5%, Line:12.5%, Star:12.5%, Binary:12.5%
			case 0: case 1: case 2: case 3: case 4:
			edges = getTreeRandom(n, index_offset); break;
			case 5: 
			edges = getTreeLine(n, index_offset); break;
			case 6: 
			edges = getTreeStar(n, index_offset); break;
			case 7: 
			edges = getTreeBinary(n, index_offset); break;
		}
		return edges;
	}
};

RandomGenerator rnd;

// ----------------------------------------------------------------------------------------

#define SUBTASK 6

int main(){

    ll T;
    cin>>T;

    ofstream output;

    for (ll t = 0; t < T; t++){
        output.close();
        string idxStr = ""; 
        if (t < 9) idxStr = "0";
        idxStr += to_string(t+1);
        string path = "sub" + to_string(SUBTASK) + "_tests/input/test_in_" + to_string(SUBTASK) +  "_" + idxStr + ".txt";
        output.open(path);

        if (!output.is_open()){
            cout<<"!! ERROR OPENING FILE"<<endl;
            return 0;
        }

        ll N, M, K, max_L, min_cell_val, max_cell_val;
        cin>>N>>M>>K>>max_L>>min_cell_val>>max_cell_val;

        if (max_L >= M){
            cout<<"!! INVALID INPUT - "<<t<<endl;
            return 0;
        }

        //main parameters
        output<<N<<" "<<M<<" "<<K<<endl;

        //layers
        for (ll i = 0; i<M; i++){
            for (ll j = 0; j < K; j++){
                for (ll k = 0; k < K; k++){
                    ll cell = rnd.getNum(min_cell_val, max_cell_val);
                    if (t == T-1){  //last test => max val edge case
                        cell = max_cell_val;
                        if (i % 2) cell *= -1;
                    }
                    output<<cell<<" ";
                }
                output<<endl;
            }
        }

        //inputs
        for (ll i = 0; i<N; i++){
            ll L = rnd.getNum(0, max_L);
            ll R = rnd.getNum(L, M-1);
            if (t == T-1 && i == N-1){  //last test => max val edge case
                L = 0;
                R = M-1;
            }
            output<<L<<" "<<R<<endl;
            for (ll j = 0; j < K; j++){
                for (ll k = 0; k < K; k++){
                    ll cell = rnd.getNum(min_cell_val, max_cell_val);
                    if (t == T-1 && i == N-1){  //last test => max val edge case
                        cell = max_cell_val;
                    }
                    output<<cell<<" ";
                }
                output<<endl;
            }
        }
        
        //target
        for (ll j = 0; j < K; j++){
            for (ll k = 0; k < K; k++){
                ll cell = rnd.getNum(min_cell_val, max_cell_val);
                if (t == T-1){  //last test => max val edge case
                    cell = -max_cell_val;
                }
                output<<cell<<" ";
            }
            output<<endl;
        }
    }

    return 0;
}

/*
5 5 2 4 0 9
*/






























