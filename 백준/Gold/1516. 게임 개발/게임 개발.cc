
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> adj[501];
int indeg[501];
int build_time[501];
int result[501];
int main()
{
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> build_time[i];
        while(true){
            int par;
            cin >> par;
            if(par == -1) break;
            
            indeg[i]++;
            adj[par].push_back(i);
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0 )
            q.push(i);
    }
    
    while(q.empty()==false){
        auto v = q.front(); q.pop();
        result[v] += build_time[v];
        
        for(auto e : adj[v]){
            result[e] = max(result[e], result[v]);
            indeg[e] --;
            if(indeg[e] == 0) q.push(e);
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << result[i] << "\n";
    }
}









