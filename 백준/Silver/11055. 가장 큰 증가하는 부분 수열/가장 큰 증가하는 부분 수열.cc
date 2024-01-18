// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;
int n;
int dp[1001];
int seq[1001];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    for(int i = 0; i < n; i++){
        dp[i] = seq[i];
        for(int j = 0; j < i; j++){
            if (seq[i] > seq[j] && dp[i] < dp[j] + seq[i])
                dp[i] = dp[j] + seq[i];
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > max) max = dp[i];
    }
    cout << max;
    return 0;
}
