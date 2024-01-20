
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<tuple>

int n, m, k;
int map[1001][1001];
bool vis[1001][1001][11][2];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};
using namespace std;
int bfs(){
    queue<tuple<int, int, int, int, bool>> q;
    q.push({0, 0, 1, 0, true});
    while(q.empty()== false){
        auto cur = q.front(); q.pop();
        int x, y, curD, curK;
        bool isDay;
        tie(x,y,curD,curK,isDay) = cur;
        if(x == m-1 && y == n-1) return curD;
        
        for(int i = 0; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= m || nx < 0 || ny >= n || ny < 0 )continue;
            if(map[ny][nx] == 0 ){
                //그냥 이동 가능하다
                if(vis[ny][nx][curK][!isDay]) continue;
                vis[ny][nx][curK][!isDay] = true;
                q.push({nx,ny,curD + 1,curK,!isDay});
            }else {
                //벽이다 낮에만 부술 수 있다. 
                if(curK >= k )continue; //어차피 못부순다.
                if(isDay) {
                    //낮이다 부수고 이동하자.
                    if(vis[ny][nx][curK+1][!isDay]) continue;
                    vis[ny][nx][curK+1][!isDay] = true;
                    q.push({nx,ny,curD+1,curK+1,!isDay});
                }else {
                    //밤이다 대기하자.
                    if(vis[y][x][curK][!isDay]) continue;
                    vis[y][x][curK][!isDay] = true;
                    q.push({x,y,curD+1,curK,!isDay});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            map[i][j] = input[j] - '0';
        }
    }
    cout << bfs();
}
