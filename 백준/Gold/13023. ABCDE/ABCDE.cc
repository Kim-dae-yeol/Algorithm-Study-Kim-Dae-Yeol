
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;
int n, m;
vector<int> adj[2000];
bool vis[2000];
bool found = false;

void dfs(int start, int cnt){
    if(cnt == 5){
        found = true;
        return; 
    }
    
    for(const auto e : adj[start]){
        if(vis[e]) continue;
        
        vis[e] = true;
        dfs(e, cnt + 1);
        vis[e] = false;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int f, t;
        cin >> f >> t;
        
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    
    for(int i = 0; i < n && !found; i++){
        vis[i] = true;
        dfs(i, 1);
        vis[i] = false;
    }    
    
    cout << found;
    return 0;
}
