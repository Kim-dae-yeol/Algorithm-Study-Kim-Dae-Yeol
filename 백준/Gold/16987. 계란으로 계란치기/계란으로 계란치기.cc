
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>
using namespace std;

int n;
int arr_hp[8];
int arr_weight[8];


int dfs(int start, int broken){
    if(start >= n) return broken;
    int ret = broken;
    if(arr_hp[start] <= 0) return dfs(start + 1,broken);
    //제일 왼쪽 계란을 잡았다.
        
    for(int j = 0 ; j < n; j++){
        if(start == j)continue;
        if(arr_hp[j] <= 0) continue;
        
        arr_hp[start] -= arr_weight[j];
        arr_hp[j] -= arr_weight[start];
        if(arr_hp[start] <= 0 ) broken++;
        if(arr_hp[j] <= 0) broken++;
        ret = max(ret, dfs(start + 1, broken)); //다음 계란을 잡는다.
        if(arr_hp[start] <= 0 ) broken--;
        if(arr_hp[j] <= 0) broken--;
        arr_hp[start] += arr_weight[j];
        arr_hp[j] += arr_weight[start];
    }
    
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> arr_hp[i] >> arr_weight[i];
    }
    cout << dfs(0, 0);
    return 0;
}

