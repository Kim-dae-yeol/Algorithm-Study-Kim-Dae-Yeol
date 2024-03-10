#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[3][101][101];
int main(){
    cin >> n >> m;
    for(int k = 0; k < 2; k ++)
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                cin >> mat[k][i][j];
            }
        }
        
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            mat[2][i][j] = mat[0][i][j] + mat[1][i][j];
        }
    }
    
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << mat[2][i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}