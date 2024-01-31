#include<bits/stdc++.h>
using namespace std;

int vis_time[500001][2];
int main(){
    int n,k;
    cin >> n >> k;
    queue<pair<int, int>>q;
    
    if(n == k){
        cout << 0;
        return 0;
    }
    
    q.push({n, 0});
    while(q.empty()== false){
        auto cur = q.front(); q.pop();
        for(auto nxt : {cur.first + 1, cur.first - 1, cur.first * 2}){
            int nt = cur.second + 1;
            if(nxt < 0 || nxt > 500000) continue;
            if(vis_time[nxt][nt % 2]) continue;
            
            vis_time[nxt][nt % 2] = nt;
            q.push({nxt,nt});
        }
    }
    
    int t = 0;
    while(k <= 500000){
        t++;
        k += t;
        if( k > 500000) break;
        if(vis_time[k][t % 2] != 0 && vis_time[k][t % 2] <= t){
            cout << t; 
            return 0;
        }
    }
    cout << -1;
}