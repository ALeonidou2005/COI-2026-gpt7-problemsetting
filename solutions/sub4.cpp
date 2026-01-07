// Problem: COI 2026 - Round A - "GPT-7"
// Sample Solution - Subtask 4
// Author: Antreas Leonidou
// Date: 22/12/25

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second

typedef pair<ll,ll> ii;
typedef pair<ii,ii> iiii;

#define MAX_M 100000
#define MAX_N 100000
#define MAX_K 1

ll layer_matrices[MAX_M];
iiii input[MAX_N];
ll target_matrix;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //input:

    ll N, M, K;
    cin>>N>>M>>K;

    for (ll i = 0; i<M; i++){
        cin>>layer_matrices[i];
    }

    for (ll i = 0; i<N; i++){
        ll L, R;
        cin>>L>>R;
        ll input_matrix;
        cin>>input_matrix;
        input[i] = iiii(ii(L,R), ii(input_matrix, i));
    }

    cin>>target_matrix;

    // sort inputs:

    sort(input, input+N);

    // solve:

    ll minError = -1, minErrorIdx = -1;
    ll p = 0;
    ll cumulative_sum_matrix = 0;
    for (ll i = 0; i<N; i++){
        ll L = input[i].F.F;
        ll R = input[i].F.S;
        ll input_matrix = input[i].S.F;
        ll input_idx = input[i].S.S;

        // continue calculating cumulative sum:
        while (p <= R){
            if (p % 2){
                cumulative_sum_matrix -= layer_matrices[p];
            }
            else{
                cumulative_sum_matrix += layer_matrices[p];
            }
            p++;
        }

        ll output_matrix = input_matrix + cumulative_sum_matrix;

        //calc error:
        ll cell_dif = (output_matrix - target_matrix);
        ll curError = cell_dif * cell_dif;

        //update minimum error:
        if (curError < minError || minError == -1 || (curError == minError && input_idx < minErrorIdx)){
            minError = curError;
            minErrorIdx = input_idx;
        }
    }

    cout<<minErrorIdx<<" "<<minError<<endl;
    
    return 0;
}

/*

Test Sample for Subtask 4:

Input:
3 5 1
7 
1 
6 
7 
5 
0 4
1 
0 0
9 
0 2
0 
9 

Output:
0 4

*/
