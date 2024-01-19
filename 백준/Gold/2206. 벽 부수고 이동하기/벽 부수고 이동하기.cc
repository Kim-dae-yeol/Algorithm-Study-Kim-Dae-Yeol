// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
int map[1001][1001];
int dist[1001][1001][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dz[2] = {0, 1};
// wall : 1
// blank : 0
// start : 1, 1
int bfs(int n, int m){
    queue<tuple<int, int, int, bool>> q;
    q.push(make_tuple(1, 1, 1, false));
    dist[1][1][0] = 0;
    while(q.empty() == false){
        auto cur = q.front(); q.pop();
        int x, y, z;
        bool isBreak;
        tie(x, y, z, isBreak) = cur;
        if(x == m && y == n){return z;}
        // cout << "x : "<< x << ", y :" << y << endl;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > m || ny > n || nx <= 0 || ny <= 0) continue;
            
            if(map[ny][nx] == 0){
                if(dist[ny][nx][isBreak] == -1){
                    dist[ny][nx][isBreak] = z + 1;
                    q.push(make_tuple(nx, ny, z + 1, isBreak));
                }
            }else{
                if(!isBreak && dist[ny][nx][1] == -1){
                    dist[ny][nx][1] = z + 1;
                    q.push(make_tuple(nx, ny, z + 1, true));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string input;
        cin >> input;
        int len = input.length();
        for(int j = 1; j <= m; j++){
            map[i][j] = input[j-1] - '0';
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;
    cout << bfs(n, m);
    return 0;
}
