
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int seq[1001];
int dp[1001];
int path[1001];

int _lis(int start){
    int &ret = dp[start];
    if(ret != 0) return ret;
    
    ret = 1;
    for(int i = start+1; i < n; i++){
        if(seq[start] < seq[i]){
            if(ret < _lis(i) + 1){
                ret = dp[i] + 1;
                path[start] = i;
            }
        }
    }
    return ret;
}

void lis(){
    fill(path, path + n, -1);
    for(int i = 0; i < n; i++){
        _lis(i);
    }
    
    int lisValue = 0;
    int idx = -1;
    for(int i = 0; i < n;i++){
        if(lisValue < dp[i]) {
            lisValue = dp[i];
            idx = i;
        }
    }
    cout << lisValue <<"\n";
    for(int i = idx; i != -1; i = path[i]){
        cout << seq[i] << " ";
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> seq[i];
        
    lis();
    return 0;
}
