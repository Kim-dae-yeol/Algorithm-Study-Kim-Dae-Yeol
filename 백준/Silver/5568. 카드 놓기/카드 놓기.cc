
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, k;
bool isSelected[10];
vector<int> selected;
vector<int> nums;
set<string> result;

void dfs(int start, int cnt){
    if(cnt == k){
        string s;
        for(int e : selected){
            s += to_string(e);
        }
        result.insert(s);
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(isSelected[i]) continue;
        
        selected.push_back(nums[i]);
        isSelected[i] = true;
        
        dfs(i, cnt + 1);
        
        isSelected[i] = false;
        selected.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    dfs(0, 0);
    cout << result.size();
    return 0;
}
