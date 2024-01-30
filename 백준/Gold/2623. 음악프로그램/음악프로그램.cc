#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[1001];
int indeg[1001];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int num;
        int a;
        int prev = -1;
        
        cin >> num;
        while(num--){
            cin >> a;
            if(prev != -1) {
                adj[prev].push_back(a);
                indeg[a]++;
            }
            prev = a;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> result;
    while(q.empty()==false){
        auto cur = q.front(); q.pop();
        result.push_back(cur);
        for(auto e : adj[cur]){
            indeg[e]--;
            if(indeg[e] == 0)
                q.push(e);
        }
    }
    
    if(result.size() == n){
        for(auto e : result){
            cout << e << "\n";
        }
    }else {
        cout << 0 << "\n";
    }
}