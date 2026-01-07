// Problem: COI 2026 - Round A - "GPT-7"
// Sample Solution - Subtask 5
// Author: Antreas Leonidou
// Date: 21/12/25

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_M 100000
#define MAX_N 100000
#define MAX_K 1

ll layer_matrices[MAX_M];
ll input_matrices[MAX_N];
ll input_L[MAX_N], input_R[MAX_N];
ll target_matrix;
ll prefix_sum_matrices[2][MAX_M];

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
        cin>>input_L[i]>>input_R[i];
        cin>>input_matrices[i];
    }

    cin>>target_matrix;

    // prepare prefix sums:

    prefix_sum_matrices[0][0] = layer_matrices[0];
    prefix_sum_matrices[1][0] = -layer_matrices[0];
    for (ll i = 1; i<M; i++){
        if (i % 2){
            prefix_sum_matrices[0][i] = prefix_sum_matrices[0][i-1] - layer_matrices[i];
            prefix_sum_matrices[1][i] = prefix_sum_matrices[1][i-1] + layer_matrices[i];
        }
        else{
            prefix_sum_matrices[0][i] = prefix_sum_matrices[0][i-1] + layer_matrices[i];
            prefix_sum_matrices[1][i] = prefix_sum_matrices[1][i-1] - layer_matrices[i];
        }
    }

    // solve:

    ll minError = -1, minErrorIdx = -1;
    for (ll i = 0; i<N; i++){
        ll L = input_L[i];
        ll R = input_R[i];

        //calc range sum (using prefix sums):
        ll range_sum_matrix;
        if (L == 0){
            range_sum_matrix = input_matrices[i] + prefix_sum_matrices[0][R];
        }
        else{
            range_sum_matrix = input_matrices[i] + prefix_sum_matrices[L%2][R] - prefix_sum_matrices[L%2][L-1];
        }

        //calc error:
        ll cell_dif = (range_sum_matrix - target_matrix);
        ll curError = cell_dif * cell_dif;

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

Test Sample for Subtask 5:

Input:
3 5 1
9 
5 
2 
7 
0 
0 3
1 
2 3
7 
1 1
2 
6 

Output:
2 1

*/
