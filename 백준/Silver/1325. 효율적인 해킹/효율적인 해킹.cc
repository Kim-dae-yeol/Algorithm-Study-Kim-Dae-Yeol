#include<bits/stdc++.h>

using namespace std;
vector<int> adj[10001];
vector<pair<int, int>> result;
bool vis[10001];
int maxConnected = 0;

void solve(const int& n){
    queue<int> node_q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            vis[j] = false;
        }
        
        vis[i] = true;
        int connected = 1;
        
        for(const auto& nextTo : adj[i]){
            if(vis[nextTo]){ continue; }
            
            vis[nextTo] = true;
            connected++;
            node_q.push(nextTo);
                
            while(!node_q.empty()){
                int cur = node_q.front();
                node_q.pop();
                
                for(const auto& value : adj[cur]){
                    if(!vis[value]){
                        vis[value] = true;
                        connected++;
                        node_q.push(value);
                    }
                }
            }
            
            if(maxConnected < connected){
                maxConnected = connected;
            }
        }
        result.push_back({i, connected});
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int f, t;
        cin >> t >> f;
        adj[f].push_back(t);
    }
    
    solve(n);
    sort(result.begin(), result.end());
    
    for(const auto& value : result){
        if(value.second == maxConnected)
            cout << value.first << " ";
    }
}