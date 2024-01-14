#include<bits/stdc++.h>

int dp[1001][1001];
using namespace std;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string seq1;
    string seq2;
    cin >> seq1;
    cin >> seq2;
    int n = seq1.length();
    int m = seq2.length();
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= m; j++){
            if(seq1[i - 1] == seq2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];
}