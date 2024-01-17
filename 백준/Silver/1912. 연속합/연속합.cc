
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int n;
int seq[100001];
int dp[100001];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    
    dp[n] = -9999;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = max(seq[i], seq[i] + dp[i + 1]);
    }
    
    int result = -9999;
    for(int i =0; i < n; i++){
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}
