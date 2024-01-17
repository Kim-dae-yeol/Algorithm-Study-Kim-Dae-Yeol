
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int n;
int dp[10002];
int arr[10001];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = n; i >= 1 && i >= n - 1; i--)
        dp[i] = arr[i] + dp[i + 1];
        
    for(int i = n - 2; i >= 1; i--){
        dp[i] = max(arr[i] + dp[i + 2], (arr[i] + arr[i + 1] + dp[i + 3])); //1잔 마시기 vs 2잔 마시기
        dp[i] = max(dp[i], dp[i + 1] );
    }
    cout << dp[1];
}
