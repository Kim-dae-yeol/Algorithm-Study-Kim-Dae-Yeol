// Online IDE - Code Editor, Compiler, Interpreter
// 불
#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int x, y, time;
    bool isFire;
}Node;

int n, m;
bool vis[1000][1000];
vector<string> board;
Node startPos;

const char SANG = '@';
const char BLANK = '.';
const char FIRE = '*';
const char WALL = '#';
queue<Node> node_q;
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};

int bfs(){
    node_q.push(startPos);
    
    while(node_q.empty() == false){
        Node cur = node_q.front();
        node_q.pop();
        // cout << cur.x << ", " << cur.y  << ", " << cur.time << " :: " << (cur.isFire ? "Fire" : "SangGeun") << "\n";
        //4방향 탐색
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            //탈출 가능 ? 
            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                if(!cur.isFire)
                    return cur.time + 1;
                continue;
            }
                
            if(board[ny][nx] != BLANK || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            Node next;
            next.x = nx;
            next.y = ny;
            next.time = cur.time + 1;
            next.isFire = cur.isFire;
            if(cur.isFire){
                board[next.y][next.x] = FIRE;
            }
            node_q.push(next);
        }
    }
    return -1;
}

int main()
{
    //EOF
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 0; i < n; i++){
            string input;
            cin >> input;
            board.push_back(input);
            for (int j = 0; j < m; j++){
                if(board[i][j] == SANG){
                    startPos.x = j;
                    startPos.y = i;
                    startPos.time = 0;
                    startPos.isFire = false;
                    board[i][j] = BLANK;
                }else if(board[i][j] == FIRE){
                    Node n;
                    n.x = j;
                    n.y = i;
                    n.isFire = true;
                    n.time = 0;
                    node_q.push(n);
                }
                
            }
            fill(vis[i],vis[i] + m, false);
        }
        int result = bfs();
        cout << (result == -1 ? "IMPOSSIBLE" : to_string(result)) << "\n";
        board.clear();
        while(node_q.empty() == false) node_q.pop();
    }
    return 0;
}
