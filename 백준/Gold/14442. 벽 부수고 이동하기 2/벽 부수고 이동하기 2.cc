
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<tuple>

int n, m, k;
int map[1001][1001];
bool vis[1001][1001][11];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};
using namespace std;
int bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 1, 0});
    while(q.empty() == false){
        auto cur = q.front(); q.pop();
        int x, y, curDist, curBreak;
        tie(x, y, curDist, curBreak) = cur;
        if(x == m-1 && y == n-1) return curDist;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= m || ny >= n || nx < 0 || ny < 0) continue;
            if(map[ny][nx] == 0){
                if(vis[ny][nx][curBreak])continue;
                //TODO
                vis[ny][nx][curBreak] = true;
                q.push({nx,ny,curDist + 1, curBreak});
            }else {
                if(curBreak == k || vis[ny][nx][curBreak + 1])continue;
                vis[ny][nx][curBreak + 1] = true;
                q.push({nx,ny,curDist + 1, curBreak + 1});
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
