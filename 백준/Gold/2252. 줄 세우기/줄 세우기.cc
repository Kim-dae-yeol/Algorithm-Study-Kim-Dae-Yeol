#include<bits/stdc++.h>

using namespace std;
int indeg[32001];
vector<int> adj[32001];

int n, m;

void toposort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!indeg[i]) q.push(i);
    }
    
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for(const auto ele : adj[cur]){
            indeg[ele] --;
            if(!indeg[ele]){
                q.push(ele);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    
    toposort();
}