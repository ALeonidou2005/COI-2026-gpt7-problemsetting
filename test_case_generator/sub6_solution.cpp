#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define sz(x) (ll)x.size()
#define endl "\n"
#define F first
#define S second

typedef vector <ll> vi;
typedef pair <ll,ll> ii;

#define dbg(x) cout<<#x<<": "<<x<<endl;
#define dbg2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl;

class Matrix{
    vector < vi > v;
    ll n;

public:
    Matrix(ll nn = 0){
        n = nn;
        v = vector<vi>(n, vi(n));
    }

    void set(vector <vi> vv){
        n = sz(vv);
        v = vv;
    }

    void input(){
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<n; j++){
                cin>>v[i][j];
            }
        }
    }

    ll sum(){
        ll s = 0;
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<n; j++){
                s += v[i][j];
            }
        }
        return s;
    }

    void print(){
        for (ll i =0; i<n; i++){
            cout<<i<<": ";
            for (ll j=0; j<n; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // MAIN OPERAND DEFINITIONS

    // (-)
    Matrix operator-() const {
        Matrix res = *this;
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<n; j++){
                res.v[i][j] = -v[i][j];
            }
        }
        return res;
    }

    // (+=)
    Matrix& operator+=(const Matrix& b) {
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<n; j++){
                v[i][j] += b.v[i][j];
            }
        }
        return *this;
    }

    // (*=)
    Matrix operator*=(const Matrix& b) {
        Matrix res = *this;
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<n; j++){
                v[i][j] *= b.v[i][j];
            }
        }
        return *this;
    }
    
    // SECONDARY OPERAND DEFINITIONS

    // (-=)
    Matrix& operator-=(const Matrix& b) {
        return *this += (-b);
    }

    // a + b
    Matrix operator+(const Matrix& b) const {
        Matrix tmp = *this;
        tmp += b;
        return tmp;
    }

    // a - b
    Matrix operator-(const Matrix& b) const {
        Matrix tmp = *this;
        tmp -= b;
        return tmp;
    }

    // a * b
    Matrix operator*(const Matrix& b) const {
        Matrix tmp = *this;
        tmp *= b;
        return tmp;
    }
};

ll get_error(Matrix &a, Matrix &b){
    Matrix dif = (a - b);
    return (dif * dif).sum();
}

Matrix get_sum(ll l, ll r, vector <Matrix> &v){
    if (l == 0) return v[r];
    return v[r] - v[l-1];
}

//-----SPEED TEST------

#include <unistd.h>
#include <chrono>
chrono::high_resolution_clock::time_point start;
chrono::high_resolution_clock::time_point stop;
chrono::duration<ld> dur;
void timerStart(){
	start = std::chrono::high_resolution_clock::now();
}
void timerStop(){
	stop = std::chrono::high_resolution_clock::now();
	dur = chrono::duration_cast<std::chrono::microseconds>(stop - start);
}
ld timerDuration(){
	return dur.count();
	//NOTE: Duration is given in microsecond precision (μs)
}

//-----------------------

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // timerStart();

    ll N, M, K;
    cin>>N>>M>>K;

    // cout<<"Reading..."<<endl;
    // cout.flush();

    //input layers
    vector < Matrix > layer(M, Matrix(K));
    for (ll i = 0; i<M; i++){
        layer[i].input();
    }

    //input inputs
    vector < pair<Matrix, ii> > inputs(N);
    for (ll i = 0; i<N; i++){
        ll L, R;
        cin>>L>>R;
        Matrix input_mat(K);
        input_mat.input();
        inputs[i] = { input_mat, ii(L, R) };
    }

    //input target
    Matrix targetMatrix(K);
    targetMatrix.input();
    
    // cout<<"Processing..."<<endl;
    // cout.flush();

    //calculate prefix sums
    vector <Matrix> pref_0(M, Matrix(K));
    vector <Matrix> pref_1(M, Matrix(K));
    pref_0[0] = layer[0];
    pref_1[0] = -layer[0];
    for (ll i = 1; i<M; i++){
        if (i % 2 == 0){
            pref_0[i] = pref_0[i-1] + layer[i];
            pref_1[i] = pref_1[i-1] - layer[i];
        }
        else{
            pref_0[i] = pref_0[i-1] - layer[i];
            pref_1[i] = pref_1[i-1] + layer[i];          
        }
    }

    // cout<<"Solving..."<<endl;
    // cout.flush();

    //solve
    ll minError = -1, minIndex = -1;
    for (ll i = 0; i<N; i++){
        // if (i % 1000 == 0){
        //     cout<<i<<endl;
        //     cout.flush();
        // }
        ll L = inputs[i].S.F;
        ll R = inputs[i].S.S;
        Matrix inputMatrix = inputs[i].F;
        Matrix outputMatrix = inputMatrix;

        if (L % 2 == 0){
            outputMatrix += get_sum(L, R, pref_0);
        }
        else{
            outputMatrix += get_sum(L, R, pref_1);
        }
        
        ll curError = get_error(outputMatrix, targetMatrix);
        if (curError < minError || minIndex == -1){
            minIndex = i;
            minError = curError;
        }
    }

    cout<<minIndex<<" "<<minError<<endl;

    // timerStop();
    // cout<<"Time taken: "<<fixed<<setprecision(3)<<timerDuration()<<" s"<<endl;

    return 0;
}

/*
2 3 2
1 4
7 0
3 2
5 1
0 6
2 8
0 2
2 1
0 2
1 1
3 3
2 9
4 5
6 7
*/
