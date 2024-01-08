
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;

int k, v, e;
bool vis[20001];
bool team[20001];
bool isBiTree;

vector<int> adj[20001];

void dfs(int cur, bool isOddTeam){
    // cout << "in dfs : " << cur << " - " << (isOddTeam ? "TRUE" : "FALSE") << "\n";
    for(auto ele : adj[cur]){
        // cout << "ele : " << ele << "\n";
        if(vis[ele] && isOddTeam == team[ele]) { isBiTree = false; return;}
        if(vis[ele]) continue;
        
        vis[ele] = true;
        team[ele] = !isOddTeam;
        dfs(ele, !isOddTeam);
    }
}

int main()
{
    cin >> k;
    vector<bool> result;
    while(k--){
        cin >> v >> e;
        for(int i = 0; i < e; i++){
            int f, t;
            cin >> f >> t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }
        
        isBiTree = true;
        for(int i = 1; i <= v; i++){
            if(!isBiTree) break;
            if(vis[i]) continue;
            
            vis[i] = true;
            team[i] = true;
            dfs(i, true);
        }
        
        
        result.push_back(isBiTree);
        fill(vis, vis + v + 1, false);
        for(int i = 1; i <= v; i++) adj[i].clear();
    }
    for(const auto& ele : result){
        cout << (ele ? "YES" : "NO" ) << "\n";
    }
    return 0;
}
