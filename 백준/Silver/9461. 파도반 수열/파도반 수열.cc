
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int t,n;
long long dp[105];
int main()
{
    cin >> t;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    // dp[7] = 
    while(t--){
        cin >> n;
        for(int i = 6; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 5];
        }
        cout << dp[n] << "\n";
    }
}
