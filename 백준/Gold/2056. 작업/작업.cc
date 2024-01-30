#include<bits/stdc++.h>

using namespace std;
int n;
int task_time[10001];
vector<int> adj[10001];
int result[10001];
int indeg[10001];
int main(){
    cin >> n;
    for(int i = 1; i <= n;i++){
        int e;
        cin >> task_time[i];
        cin >> e;
        for(int j = 0 ; j < e; j++){
            int nxt;
            cin >> nxt;
            adj[i].push_back(nxt);
            indeg[nxt]++;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        auto v = q.front(); q.pop();
        result[v] += task_time[v];
        for(auto e : adj[v]){
            result[e] = max(result[e], result[v]);
            indeg[e]--;
            if(indeg[e] == 0){
                q.push(e);
            }
        }
    }
    
    int ret = 0;
    for(int i = 1; i <= n; i++){
        ret = max(ret, result[i]);
    }
    cout << ret;
}