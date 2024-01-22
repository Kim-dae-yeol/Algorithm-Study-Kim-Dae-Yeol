
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[11];
int fact(int n){
    if(dp[n]) return dp[n];
    int&ret = dp[n];
    
    return ret = n * fact(n-1);
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //이항 계수 구하는 프로그램 
    //n! / K!
    dp[0] = 1;
    dp[1] = 1;
    int n, k;
    cin >> n >> k;
    int s = fact(n); int m = fact(n - k);
    cout << (s / m) / fact(k);
}
