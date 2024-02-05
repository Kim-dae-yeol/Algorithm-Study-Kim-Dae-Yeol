
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
bool vis[1001];

int dfs(int from, int to, int dist){
    vis[from] = true;
    if(from == to) {
         return dist;
    }
    
    for(auto e : adj[from]){
        if(vis[e.second]) continue;
        int ret = dfs(e.second, to, dist + e.first);
        if(ret == -1) continue;
        return ret;
    }
    
    return -1;
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n - 1; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        
        adj[a].push_back({dist, b});
        adj[b].push_back({dist, a});
    }
    for(int i = 0 ; i < m; i++){
        int from, to;
        cin >> from >> to;
        fill(vis, vis + n + 1, false);
        cout << dfs(from, to, 0) << "\n";
    }
    
    return 0;
}
