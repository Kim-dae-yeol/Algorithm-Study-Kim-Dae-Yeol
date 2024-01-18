#include <bits/stdc++.h>
using namespace std;
long long dp[101][10];
int main(){
    int n;
    cin >> n;
    fill(dp[1], dp[1] + 10, 1);
    
    for(int len = 2; len <= n; len++){
        for(int start = 0; start < 10; start ++){
            if(start == 0 ){
                dp[len][start] = dp[len - 1][start + 1] % 1000000000;
            }else if(start == 9){
                dp[len][start] = dp[len - 1][start - 1] % 1000000000;
            }else {
                dp[len][start] = dp[len - 1][start + 1] + dp[len - 1][start - 1] % 1000000000;
            }
        }
    }
    long long sum = 0;
    for(int i = 1; i<= 9; i++)
        sum += (dp[n][i] % 1000000000);
    cout << sum % 1000000000;
}