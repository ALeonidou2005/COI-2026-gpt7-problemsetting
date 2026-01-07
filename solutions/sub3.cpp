// Problem: COI 2026 - Round A - "GPT-7"
// Sample Solution - Subtask 3
// Author: Antreas Leonidou
// Date: 21/12/25

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_M 1000
#define MAX_N 1000
#define MAX_K 10

ll layer_matrices[MAX_M][MAX_K][MAX_K];
ll input_matrices[MAX_N][MAX_K][MAX_K];
ll target_matrix[MAX_K][MAX_K];
ll input_L[MAX_N], input_R[MAX_N];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //input:

    ll N, M, K;
    cin>>N>>M>>K;

    for (ll i = 0; i<M; i++){
        for (ll j =0; j<K; j++){
            for (ll k = 0; k<K; k++){
                cin>>layer_matrices[i][j][k];
            }
        }
    }

    for (ll i = 0; i<N; i++){
        cin>>input_L[i]>>input_R[i];
        for (ll j =0; j<K; j++){
            for (ll k = 0; k<K; k++){
                cin>>input_matrices[i][j][k];
            }
        }
    }

    for (ll i =0; i<K; i++){
        for (ll j = 0; j<K; j++){
            cin>>target_matrix[i][j];
        }
    }

    // solve:

    ll minError = -1, minErrorIdx = -1;
    for (ll i = 0; i<N; i++){
        ll L = input_L[i];
        ll R = input_R[i];

        //calc range sum:
        ll range_sum_matrix[K][K];
        for (ll j =0; j<K; j++){
            for (ll k = 0; k<K; k++){
                range_sum_matrix[j][k] = input_matrices[i][j][k];
            }
        }
        for (ll p = L; p <= R; p++){
            for (ll j =0; j<K; j++){
                for (ll k = 0; k<K; k++){
                    if ((p-L) % 2 == 0){
                        range_sum_matrix[j][k] += layer_matrices[p][j][k];
                    }
                    else{
                        range_sum_matrix[j][k] -= layer_matrices[p][j][k];
                    }
                }
            }
        }

        //calc error:
        ll curError = 0;
        for (ll j =0; j<K; j++){
            for (ll k = 0; k<K; k++){
                ll cell_dif = (range_sum_matrix[j][k] - target_matrix[j][k]);
                ll cell_error = cell_dif * cell_dif;
                curError += cell_error;
            }
        }

        //update minimum error:
        if (curError < minError || minError == -1){
            minError = curError;
            minErrorIdx = i;
        }
    }

    cout<<minErrorIdx<<" "<<minError<<endl;
    
    return 0;
}

/*

Test Sample for Subtask 3:

Input:
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

Output:
1 14

*/
