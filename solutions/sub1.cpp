// Problem: COI 2026 - Round A - "GPT-7"
// Sample Solution - Subtask 1
// Author: Antreas Leonidou
// Date: 21/12/25

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_M 100

ll layer_matrices[MAX_M];
ll input_matrix;
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

    ll L, R;
    cin>>L>>R;
    cin>>input_matrix;

    cin>>target_matrix;

    // solve:
    
    ll output_matrix = input_matrix;
    for (ll i = L; i<= R; i++){
        if ((i-L) % 2 == 0){
            output_matrix += layer_matrices[i];
        }
        else{
            output_matrix -= layer_matrices[i];
        }
    }
    ll dif = output_matrix - target_matrix;
    ll error = dif * dif;

    cout<<"0 "<<error<<endl;
    
    return 0;
}

/*

Test Sample for Subtask 1:

Input:
1 1 1
0 
0 0
8 
2 

Output:
0 36

*/
