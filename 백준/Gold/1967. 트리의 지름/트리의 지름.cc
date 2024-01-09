// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

int v;
vector<pair<int, int>> adj[10001];
int maxDist = -214700000;
int maxNode;
bool vis[10001];

void dfs(int node, int dist){
    // cout << "Node" << node << endl;
    vis[node] = true;
    
    if(maxDist < dist){
        maxDist = dist;
        maxNode = node;
    }
    
    for(auto e : adj[node]){
        if(!vis[e.first]){
            dfs(e.first, dist + e.second);
        }
    }
}

int main()
{
    cin >> v;
    
    for(int i = 0; i < v - 1; i++){
        int par, ch, dist;
        cin >> par >> ch >> dist;
        adj[par].push_back({ch, dist});
        adj[ch].push_back({par, dist});
    }
    
    dfs(1,0);
    fill(vis, vis + v + 1, false);
    
    dfs(maxNode, 0);
    cout << maxDist;
}
