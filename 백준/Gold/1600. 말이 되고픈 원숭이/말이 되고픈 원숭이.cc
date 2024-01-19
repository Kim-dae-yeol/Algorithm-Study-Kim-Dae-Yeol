// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
int map[201][201];
bool dist[201][201][31];
int dx[12] = {0, 1, 0, -1, -1, 1, 2, 2, 1, -1, -2, -2};
int dy[12] = {-1, 0, 1, 0, -2, -2, -1, 1, 2, 2, 1, -1};
int w, h, k;
// wall : 1
// blank : 0
// start : 1, 1r
// 벽부수고 이동하기와 거의 동일한 로직사용
int bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(1, 1, 0, 0));
    while(q.empty()==false){
        auto cur = q.front();q.pop();
        int x, y, curD, curK;
        tie(x, y, curD, curK) = cur;
        if(x == w && y == h) {return curD;}
        
        for(int i = 11; i >= 0; i--){
            if(i >= 4 && curK >= k) continue;
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > w || nx <= 0 || ny > h || ny <= 0) continue;
            if(map[ny][nx]) continue;
            int nk = curK;
            if(i >= 4){
                nk = curK + 1;
            }
            if(map[ny][nx] == 0 && dist[ny][nx][nk] == false){
                dist[ny][nx][nk] = true;
                q.push(make_tuple(nx, ny, curD + 1, nk));
            }
        }
    }
    return -1;
}

int main()
{
    cin >> k;
    cin >> w >> h;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            for(int kk = 0; kk <= k; kk++){
                dist[i][j][kk] = false;
            }
        }
    }
    cout << bfs();
}
