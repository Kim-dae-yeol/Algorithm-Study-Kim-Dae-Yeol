
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[32001];
int indeg[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(!indeg[i])
            pq.push(i);
    }
    
    while(pq.empty()== false){
        auto v = pq.top(); pq.pop();
        cout << v << " ";
        for(auto e : adj[v]){
            indeg[e]--;
            if(indeg[e] == 0)
                pq.push(e);
        }
    }
    return 0;
}
