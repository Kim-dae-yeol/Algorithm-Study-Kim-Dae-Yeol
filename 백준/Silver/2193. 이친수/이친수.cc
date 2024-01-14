#include<iostream>
long long dp[100][2];
using namespace std;
int main(void) {
    int N;
    cin >> N;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[N][1];
}