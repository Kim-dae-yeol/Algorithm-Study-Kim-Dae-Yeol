// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
vector<pair<int, long long>> adj[1001];
bool isInMst[1001];
int main()
{
    priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        long long cost;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }
    
    int node = 1;
    isInMst[node] = true;
    int cnt = 0;
    long long cost = 0;
    
    do{
        for(auto e : adj[node]){
            if(isInMst[e.first]) continue;
            pq.push({e.second, e.first});
        }
        
        while(true){
            auto cur = pq.top(); pq.pop();
            if(isInMst[cur.second]) continue;
            
            cnt ++;
            isInMst[cur.second] = true;
            node = cur.second;
            cost += cur.first;
            break;
        }
    }while(cnt < n - 1);
    cout << cost;
    return 0;
}
