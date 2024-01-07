// Online IDE - Code Editor, Compiler, Interpreter
// 불
#include<bits/stdc++.h>

using namespace std;

int n, m;
bool vis[1000][1000];
vector<string> board;
pair<int, int> startPos;
queue<tuple<int, int, int>> q;

const char FIRE = 'F';
const char WALL = '#';
const char BLANK = '.';
const char START = 'J';

int dc[4]{0,1,0,-1};
int dr[4]{-1,0,1,0};

void bfs(){
    q.push({startPos.first, startPos.second, 0});
    
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        int r, c, dist;
        tie(r, c, dist) = cur;
        bool isFire = board[r][c] == FIRE;
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            
            if(!isFire && (nr < 0 || nr >= n || nc < 0 || nc >= m)){
                cout << dist + 1;
                return;
            }
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m){ 
                continue;
            }
            
            if(vis[nr][nc] || board[nr][nc] != BLANK) continue;
            if(isFire) board[nr][nc] = FIRE;
            
            vis[nr][nc] = true;
            q.push({nr, nc, dist + 1});
        }
    }
    
    cout << "IMPOSSIBLE";
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        board.push_back(input);
        for(int j = 0; j < m; j++){
            if(board[i][j] == FIRE)
                q.push({i, j, 0});
            else if(board[i][j] == START){
                startPos.first = i;
                startPos.second = j;
            }
        }
    }
    
    bfs();
}
