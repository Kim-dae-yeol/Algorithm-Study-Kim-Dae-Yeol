
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int t,n, m;
int dp[31][31];

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
            dp[1][i] = i;
            
        for(int i = 2; i <= n; i++){
            for(int j = i; j <= m; j++){
                int sum = 0;
                for(int k = j; k >= i ; k--){
                    // cout << "i-1 : " << i - 1 << ", k : " << k  << endl;
                    sum += dp[i - 1][k - 1];
                    // cout <<  "sum += " << dp[i-1][k - 1] << endl;
                }
                dp[i][j] = sum;
            }
        }
        
        cout << dp[n][m] << "\n";
    }
}
