#include<bits/stdc++.h>

using namespace std;

int n,k;
int dist[200002];
int result[200002];

int main(void) {
    cin >> n >> k;
    fill(dist, dist + 200000 + 1, -1);
    dist[n] = 0;
    result[n] = 1;
    queue<int> q;
    q.push(n);
    bool flag = false;
    while(!q.empty()){
        //TOOD : cur -> 이동 가능한 위치로 이동 시키기
        int cur = q.front(); q.pop();
        // cout << cur << " : " << dist[cur] << endl;
        if(cur == k) {
            flag = true;
            continue;
        }
        
        if(cur * 2 >= 0 && cur * 2 <= 200000 ){
            if(dist[cur * 2] == -1 ){
                dist[cur * 2] = dist[cur] + 1;
                result[cur*2] += result[cur];
                q.push(cur * 2);
            }else if(dist[cur * 2] == dist[cur] + 1){
                result[cur*2]+= result[cur];
            }
        }
        
        for(int nxt : {cur - 1, cur + 1}){
            if(nxt < 0 || nxt > 200000 ) continue;
            if(dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                result[nxt] += result[cur];
                q.push(nxt);
            }else if(dist[nxt] >= dist[cur] + 1){
                result[nxt] += result[cur];
            }
        }
    }
    cout << dist[k] << "\n" << result[k];
}