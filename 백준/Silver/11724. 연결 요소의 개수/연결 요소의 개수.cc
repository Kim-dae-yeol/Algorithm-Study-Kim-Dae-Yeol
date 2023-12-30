#include<iostream>
#include<queue>

int adj[1001][1001];
bool vis[1001];

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int f, t;
        cin >> f >> t;
        adj[f][t] = 1;
        adj[t][f] = 1;
    }
    queue<int> pos_q;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]){continue;}
        vis[i] = true;
        cnt++;
        pos_q.push(i);
        while(!pos_q.empty()){
            int cur = pos_q.front();
            pos_q.pop();
            
            for(int j = 1; j <= n; j++){
                if(adj[cur][j] == 0 || vis[j]){continue;}
                vis[j] = true;
                pos_q.push(j);
            }
        }
    }
    
    cout << cnt;
}