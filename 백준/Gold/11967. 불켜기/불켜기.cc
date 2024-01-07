
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, m;

vector<pair<int, int>> adj[101][101];
bool vis[101][101];
bool canMove[101][101];

int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

void bfs(){
    int room = 1;
    vis[1][1] = true;
    canMove[1][1] = true;
    queue<pair<int, int>> q;
    q.push({1, 1});
    
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        
        bool isChanged = false;
        //불을 켠다.         
        for(const auto& value : adj[cur.first][cur.second]){
            if(canMove[value.first][value.second]){
                //이미 켜진 방
                continue;
            }
            isChanged = true;
            canMove[value.first][value.second] = true;
            room++;
        }
        
        if(isChanged) {
            while(q.empty() == false) q.pop();
            
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    vis[i][j] = false;
        }
        
        //이동한다.
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            
            if(vis[nx][ny] || !canMove[nx][ny]) continue;
            
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    cout << room;
}

int main()
{
    cin >> n >> m;
    while(m--){
        int fx, fy, tx, ty;
        cin >> fx >> fy >> tx >> ty;
        adj[fx][fy].push_back({tx, ty});
    }
    
    bfs();
    return 0;
}
