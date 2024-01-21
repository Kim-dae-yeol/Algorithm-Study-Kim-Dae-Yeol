
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<limits>
using namespace std;

int N;
int T[16]; int P[16];
int dp[16];
//
int solve(int start){
    if(start > N) return 0;
    int &ret = dp[start];
    if(ret != 0) return ret;
    
    for(int i = start; i < N; i++){
        if(T[i] + i <= N){
            ret = max(ret, P[i] + solve(i + T[i]));
        }
    }
    return ret;
}

int main()
{
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> T[i] >> P[i];
    }
    solve(0);
    int result = 0;
    for(int i = 0 ; i< N; i++){
        result = max(result, dp[i]);
    }
    cout << result;
}
