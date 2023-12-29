#include<iostream>
#include<queue>

using namespace std;
char board[101][101];
typedef struct position{
    int x, y;
}position;

queue<position> position_q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool vis[101][101];
void bfs(int n, bool is_rg_disorder){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]){continue;}
            vis[i][j] = true;
            position p;
            p.x = j;
            p.y = i;
            position_q.push(p);
            
            while(!position_q.empty()){
                position cur = position_q.front();
                position_q.pop();
                
                for(int k = 0; k < 4; k++){
                    int nx = cur.x + dx[k];
                    int ny = cur.y + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n){continue;}
                    if(vis[ny][nx]){continue;}
                    
                    if(is_rg_disorder){
                        if(board[ny][nx] == 'R' && board[cur.y][cur.x] == 'G'){
                            position next;
                            next.x = nx;
                            next.y = ny;
                            vis[ny][nx] = true;
                            position_q.push(next);
                        }else if(board[ny][nx] == 'G' && board[cur.y][cur.x] == 'R'){
                            position next;
                            next.x = nx;
                            next.y = ny;
                            vis[ny][nx] = true;
                            position_q.push(next);
                        }else if(board[ny][nx] == board[cur.y][cur.x]){
                        position next;
                        next.x = nx;
                        next.y = ny;
                        vis[ny][nx] = true;
                        position_q.push(next);
                    }
                    }else if(board[ny][nx] == board[cur.y][cur.x]){
                        position next;
                        next.x = nx;
                        next.y = ny;
                        vis[ny][nx] = true;
                        position_q.push(next);
                    }
                }
            }
            cnt++;
        }
    }
    cout << cnt << " ";
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    bfs(n, false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
    bfs(n, true);
}