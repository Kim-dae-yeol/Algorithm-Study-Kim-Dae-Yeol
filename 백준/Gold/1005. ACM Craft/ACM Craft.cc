#include<bits/stdc++.h>

using namespace std;
int n, k, w;
int t;
vector<int> adj[1001];
int build_time[1001];
int indeg[1001];
int result[1001];

void topo(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    
    while(q.empty()==false){
        // result[i] = 현재 노드의 빌드 시간
        // result[i] = 조상 노드의 빌드 시간 최대 + build_time[i];
        auto v = q.front(); q.pop();
        result[v] += build_time[v];
        
        for(auto e : adj[v]){
            result[e] = max(result[e], result[v]);
            indeg[e]--;
            if(indeg[e] == 0) q.push(e);
        }
    }
}

void clear_state(){
    //result, indeg, adj
    for(int i = 1; i<= n;i++){
        adj[i].clear();
        indeg[i] = 0;
        result[i] = 0;
    }
}
int main(){
    cin >> t;
    while(t--){
        
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> build_time[i];
        }
        
        for(int i = 0; i < k; i++){
            int f,t;
            cin >> f >> t;
            adj[f].push_back(t);
            indeg[t]++;
        }
        
        cin >> w;
        topo();
        cout << result[w] << "\n";
        clear_state();
    }
}