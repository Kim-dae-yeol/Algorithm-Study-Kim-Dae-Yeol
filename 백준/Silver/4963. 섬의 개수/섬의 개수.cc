#include<bits/stdc++.h>

using namespace std;

int board[50][50];
typedef struct position{
    int x,y;
}position;

int dx[8]{0,1,1,1,0,-1,-1,-1};
int dy[8]{-1,-1,0,1,1,1,0,-1};

int bfs(int w, int h){
    queue<position> pos_q;
    int vis[50][50];
    
    int ret = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            vis[i][j] = false;
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j] == 1 && !vis[i][j]){
                position land;
                land.x = j;
                land.y = i;
                pos_q.push(land);
                ret++;
                vis[i][j] = true;
                
                while(!pos_q.empty()){
                    position cur = pos_q.front();
                    pos_q.pop();
                    
                    
                    for(int k = 0; k < 8; k++){
                        int nextX = cur.x + dx[k];
                        int nextY = cur.y + dy[k];
                        
                        if(nextX < 0 || nextX >= w || nextY < 0 || nextY >= h){ continue; }
                        
                        if(vis[nextY][nextX]){ continue; }
                        
                        if(board[nextY][nextX] == 1){
                            vis[nextY][nextX] = true;
                            position next;
                            next.x = nextX;
                            next.y = nextY;
                            pos_q.push(next);
                        }
                    }
                }
            }
        }
    }
    return ret;
}

int main(){
    int w, h;
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0){break;}
        
        for(int i = 0; i< h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
            }
        }
        cout << bfs(w, h) << "\n";
    }
}