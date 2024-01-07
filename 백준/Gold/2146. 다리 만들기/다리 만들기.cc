
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, m;

int adj[101][101];
bool vis[101][101];
int lands[101][101];

int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

void dfs(int r, int c, int land){
    for(int i = 0; i < 4; i++){
        int nr = r + dy[i];
        int nc = c + dx[i];
            
        if(nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
        if(!adj[nr][nc] || vis[nr][nc]) continue;
        
        vis[nr][nc] = true;
        lands[nr][nc] = land;
        dfs(nr, nc, land);
    }
}

void bfs(int land){
    //각 대륙에서 다리를 놓아서 최소값을 업데이트한다.
    
    vector<queue<tuple<int, int, int>>> qs(land);
    
    for(int i = 0; i <= land; i++){
        queue<tuple<int, int, int>> q;
        qs.push_back(q);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj[i][j] == 1){
                qs[lands[i][j]].push({i, j, 0});
            }
        }
    }
    
    int minValue = 999999;
    for(int i = 1; i <= land; i++){
        int land = i;
        auto q = qs[i];
        
        while(q.empty() == false){
            auto cur = q.front();
            q.pop();
            int r, c, curDist;
            tie(r, c, curDist) = cur;
            
            
            for(int i = 0; i < 4; i++){
                int nr = r + dy[i];
                int nc = c + dx[i];
                
                if(nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
                if(vis[nr][nc]) continue;
                
                if(adj[nr][nc] != 0 && lands[nr][nc] != land){
                    minValue = min(minValue, curDist);
                    while(q.empty()==false) q.pop();
                    break;
                }
                
                if(adj[nr][nc] != 0) continue;
                vis[nr][nc] = true;
                q.push({nr, nc, curDist + 1});
            }
        }
        
        for(int i = 0; i <= n; i++)
            fill(vis[i], vis[i] + n + 1, false);
    }
    cout << minValue;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
    }
    
    //대륙 잇기
    int land = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=n; j++)
            if(adj[i][j] && !vis[i][j]){
                vis[i][j] = true;
                lands[i][j] = land;
                dfs(i, j, land);
                land++;
            }
            
    //Print lands         
    // cout << "=== 대륙 ===" << "\n";
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++)
    //         cout << lands[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "=== 대륙 ===" << "\n";
    
    
    for(int i = 0; i <= n; i ++)
        fill(vis[i], vis[i] + n + 1, false);
    
    //다리 만들기
    bfs(land);
    
    return 0;
}
