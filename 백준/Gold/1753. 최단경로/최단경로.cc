    // Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
    
vector<pair<int, int>> adj[20001];
int dist[20001];
int INF = 0x3f3f3f3f;

void djikstra(int start, int n){
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    
    pq.push({dist[start], start});
    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        // cout << cur.second << " : " << cur.first << endl;
        pq.pop();
        
        if(dist[cur.second] != cur.first){continue;}
        
        for(auto nxt : adj[cur.second]){
            // cout << "nxt : " << nxt.second << " : " << nxt.first << endl;
            //갱신할 필요가 없음
            if(dist[nxt.second] <= dist[cur.second] + nxt.first){continue;}
            
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    
    //Output
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF){
            cout << "INF" << "\n";
        }else {
            cout << dist[i] << "\n";
        }
        
    }
}
    
    
int main() {
    int v, e;
    int start;
    cin >> v >> e;
    cin >> start;
    for(int i = 0; i < e; i++){
        int f, t, d;
        cin >> f >> t >> d;
        pair<int, int> p;
        p.first = d;
        p.second = t;
        adj[f].push_back(p);
    }
    
    fill(dist, dist + v + 1, INF);
    // cout << "----Start----" << endl;
    djikstra(start, v);
    // cout << "----End----" << endl;
    
    return 0;
}