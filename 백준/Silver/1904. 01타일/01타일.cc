// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int dp[1000001];
int main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    cout << dp[n];
    return 0;
}
