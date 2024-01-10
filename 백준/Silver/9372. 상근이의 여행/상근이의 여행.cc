#include<bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> adj[1001];
bool vis[1001];
int cnt = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    vis[1] = true;
    
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        
        for(const auto e : adj[cur]){
            if(vis[e]) continue;
            vis[e] = true;
            cnt++;
            q.push(e);
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        cnt = 0;
        fill(vis, vis + n + 1, false);
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            int f, t;
            cin >> f >> t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }
        bfs();
        cout << cnt << "\n";
    }
    
    
    return 0;
}