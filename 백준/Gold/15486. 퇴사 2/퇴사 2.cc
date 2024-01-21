// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<limits>
using namespace std;

int N;
int T[1500001]; int P[1500001];
int dp[1500001];
void solve(){
    for(int i = N-1;i>=0;i--){
        if(T[i] + i <= N){
            dp[i] = max(dp[i+1], dp[i + T[i]] + P[i]);
        }else {
            dp[i] = dp[i + 1];
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> T[i] >> P[i];
    }
    solve();
    int result = 0;
    for(int i = 0 ; i< N; i++){
        result = max(result, dp[i]);
    }
    cout << result;
}
