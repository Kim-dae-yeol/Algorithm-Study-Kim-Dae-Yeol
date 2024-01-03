#include<bits/stdc++.h>

using namespace std;

int n, m;
int board[8][8];
typedef struct position{
    int x,y;
}position;
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};

int bfs(int board[8][8]){
    int vis[8][8];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = false;
        }
    }
    
    queue<position> position_q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 2){
                position p;
                p.x = j;
                p.y = i;
                position_q.push(p);
            }
        }
    }
    
    while(!position_q.empty()){
        position cur = position_q.front();
        position_q.pop();
        
        for(int i = 0; i < 4; i++){
            int newX = cur.x + dx[i];
            int newY = cur.y + dy[i];
            if(newX < 0 || newX >= m || newY < 0 || newY >= n){continue;}
            
            if(!vis[newY][newX] && board[newY][newX] == 0){
                vis[newY][newX] = true;
                position next;
                next.x = newX;
                next.y = newY;
                position_q.push(next);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && board[i][j] == 0){
                cnt++;
            }
        }
    }
    
    return cnt;
}

int dfs(int cur, int cnt){
    if(cur == cnt){
        // cout << "call bfs\n";
        return bfs(board);
    }
    
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                board[i][j] = 1;
                ret = max(ret, dfs(cur + 1, cnt));
                board[i][j] = 0;
            }
        }
    }
    
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int value = dfs(0, 3);
    
    
    cout << value;
}