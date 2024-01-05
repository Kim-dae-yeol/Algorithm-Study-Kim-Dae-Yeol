
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n;
bool selected[8];
vector<int> seq;
void dfs(int cnt){
    if(cnt == n){
        for(const auto& num : seq)
            cout << num << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(selected[i]) continue;
        
        selected[i] = true;
        seq.push_back(i + 1);
        dfs(cnt + 1);
        seq.pop_back();
        selected[i] = false;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    cin >> n;
    dfs(0);
    return 0;
}
