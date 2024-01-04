#include<bits/stdc++.h>

using namespace std;
int adj[100][100];
int result[100][100];

void solution(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                result[j][k] = result[j][k] || (result[j][i] && result[i][k]);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
            result[i][j] = adj[i][j];
        }
    }
    
    solution(n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}