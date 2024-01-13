#include <bits/stdc++.h>
using namespace std;
int seq[2001];
bool dp[2001][2001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin>>seq[i];
        
    
    for(int k = 0; k < n; k++){
        for(int i = 1, j = k + 1; j <= n; i++, j++){
            if(k == 0) dp[i][j] = true;
            else if(k == 1) dp[i][j] = seq[i] == seq[j];
            else dp[i][j] = seq[i] == seq[j] && dp[i + 1][j-1];
        }
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        int f, t;
        cin >> f >> t;
        cout << dp[f][t] << "\n";
    }
}