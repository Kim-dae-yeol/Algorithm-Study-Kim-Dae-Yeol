
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;
int r, c;
string s[51];
int vis[51][51];

int dx[4]{0,1,0,-1};
int dy[4]{-1, 0, 1, 0};
const int STONE = 'X';
const int WATER = '*';
const int BLANK = '.';
const int DEST = 'D';
const int START = 'S';
int main()
{
    cin >> r >>c;
    pair<int, int> sPos;
    pair<int, int> dPos;
    queue<tuple<int, int, bool>> q;
    for(int i = 0; i <r;i++){
        cin >> s[i];
        for(int j = 0; j < c; j++){
            if(s[i][j] == WATER){
                q.push({i, j, true});
            }else if(s[i][j] == START){
                sPos.first = i;
                sPos.second = j;
            }else if(s[i][j]==DEST){
                s[i][j] = DEST;
                dPos.first = i;
                dPos.second = j;
            }
        }
    }
    
    vis[sPos.first][sPos.second] = 0;
    q.push({sPos.first, sPos.second, false});
    while(q.empty()==false){
        auto cur = q.front(); q.pop();
        int cr, cc;
        bool isWater;
        tie(cr, cc, isWater) = cur;
        for(int i = 0; i < 4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            
            if(nr >= r || nr < 0 || nc >= c || nc < 0) continue;
            if(isWater){
                if(s[nr][nc] == BLANK || s[nr][nc] == START){
                    s[nr][nc] = WATER;
                    q.push({nr, nc, isWater});
                }
            }else {
                if(s[nr][nc] != BLANK && s[nr][nc] != DEST) continue;
                if(vis[nr][nc] > vis[cr][cc]) continue;
                
                vis[nr][nc] = vis[cr][cc] + 1;
                s[nr][nc] = START;
                q.push({nr, nc, isWater});
            }
        }
    }
    
    if(vis[dPos.first][dPos.second]){
        cout << vis[dPos.first][dPos.second];
    }else {
        cout << "KAKTUS";
    }
}
