#include<bits/stdc++.h>
using namespace std;

int matA[101][101];
int matB[101][101];
int matC[101][101];
int main(){
    int n,m,k;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ;j ++){
            cin >> matA[i][j];
        }
    }
    
    cin >> m >> k;
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < k ;j ++){
            cin >> matB[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int jj = 0 ; jj < m; jj++){
                matC[i][j] += matA[i][jj] * matB[jj][j];
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < k; j++){
            cout << matC[i][j] << " ";
        }
        cout <<"\n";
    }
}