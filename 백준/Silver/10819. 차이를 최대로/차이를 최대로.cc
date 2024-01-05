
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> seq;
vector<int> selected;
bool isSelected[8];

int dfs(int cnt){
    
    if(cnt == n){
        int sum = 0;
        for(int i = 0; i < n - 1; i++){
            int diff = abs(selected[i] - selected[i + 1]);
            sum += diff;
        }
        return sum;
    }
    
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(isSelected[i]){ continue;}
        isSelected[i] = true;
        selected.push_back(seq[i]);
        ret = max(ret, dfs(cnt + 1));
        selected.pop_back();
        isSelected[i] = false;
    }
    
    return ret;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        seq.push_back(num);
    }
    
    cout << dfs(0);
    return 0;
}
