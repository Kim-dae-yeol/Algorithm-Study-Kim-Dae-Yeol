
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
int n,l,r;
int country[51][51];
bool vis[51][51];

int dx[4]{0,1,0,-1};
int dy[4]{-1, 0, 1, 0};
int bfs(){
    queue<pair<int, int>> q;
    bool canTrans = false;
    int ret = -1;
    do{
        for(int i = 0 ; i< n ;i ++){
            fill(vis[i],vis[i] + n, false);
        }
        
        canTrans = false;
        ret++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j]) continue;
                vis[i][j] = true;
                int sum = country[i][j];
                vector<pair<int, int>> alli;
                alli.push_back({i, j});
                q.push({i, j});
                while(q.empty() == false){
                    auto cur = q.front(); q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int ny = cur.first + dy[k];
                        int nx = cur.second + dx[k];
                        if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                        int diff = abs(country[cur.first][cur.second] - country[ny][nx]);
                        if(vis[ny][nx]) continue;
                        
                        if(diff >= l && diff <= r){
                            q.push({ny, nx});
                            vis[ny][nx] = true;
                            canTrans = true;
                            alli.push_back({ny, nx});
                            sum += country[ny][nx];
                        }
                    }
                }
                
                if(canTrans){
                    for(auto& e : alli){
                        country[e.first][e.second] = sum / alli.size();
                    }
                }
            }
        }
        
    }while(canTrans);
    
    return ret;
}
int main()
{
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> country[i][j];
        }
    }
    cout << bfs();
    
    return 0;
}
