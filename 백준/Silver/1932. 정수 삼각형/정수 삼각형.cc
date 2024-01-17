
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int n;
int tri[505][505];
int dp[505][505];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> tri[i][j];
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            dp[i][j] = tri[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout << dp[0][0];
    return 0;
}
