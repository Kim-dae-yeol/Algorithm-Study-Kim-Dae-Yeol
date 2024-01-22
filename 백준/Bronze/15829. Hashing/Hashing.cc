
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[11];
int M = 1234567891;
int r = 31;
int string_hash(int n, string s){
    int sum = 0;
    for(int i = 0; i < n; i++){
        int mult = 1;
        for(int j = 0 ; j < i; j++){
            mult *= r % M;
        }
        sum += ((s[i] - 'a' + 1) * ( mult % M ));
    }
    return sum;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; string s;
    cin >> n >> s;
    cout << string_hash(n, s);
}
