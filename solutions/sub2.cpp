// Problem: COI 2026 - Round A - "GPT-7"
// Sample Solution - Subtask 2
// Author: Antreas Leonidou
// Date: 21/12/25

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_K 10

ll layer_matrix[MAX_K][MAX_K];
ll input_matrix[MAX_K][MAX_K];
ll target_matrix[MAX_K][MAX_K];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //input:

    ll N, M, K;
    cin>>N>>M>>K;

    for (ll i =0; i<K; i++){
        for (ll j = 0; j<K; j++){
            cin>>layer_matrix[i][j];
        }
    }

    ll L, R;
    cin>>L>>R;
    for (ll i =0; i<K; i++){
        for (ll j = 0; j<K; j++){
            cin>>input_matrix[i][j];
        }
    }

    for (ll i =0; i<K; i++){
        for (ll j = 0; j<K; j++){
            cin>>target_matrix[i][j];
        }
    }

    // solve:

    ll total_error = 0;
    for (ll i =0; i<K; i++){
        for (ll j = 0; j<K; j++){
            ll output_matrix_cell = input_matrix[i][j] + layer_matrix[i][j];
            ll cell_dif = (output_matrix_cell - target_matrix[i][j]);
            ll cell_error = cell_dif * cell_dif;
            total_error += cell_error;
        }
    }

    cout<<"0 "<<total_error<<endl;
    
    return 0;
}

/*

Test Sample for Subtask 2:

Input:
1 1 2
8 8 
0 0 
0 0
9 0 
4 5 
1 7 
7 8 

Output:
0 275

*/
