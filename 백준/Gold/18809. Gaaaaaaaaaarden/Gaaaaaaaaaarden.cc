// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int garden[50][50];

const int LAKE = 0;
const int WHITE = 1;
const int BROWN = 2;
const int GREEN = 3;
const int RED = 4;
const int FLOWER = 5;

int seedGarden[50][50];
int visDay[50][50];
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};
vector<pair<int, int>> browns;
typedef struct gardenNode{
    int x, y, day, color;
}gardenNode;
int gardenCopied[50][50];
int called = 0;

int bfs(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visDay[i][j] = 0;
            gardenCopied[i][j] = garden[i][j];
        }
    }
    
    queue<gardenNode> node_q;
    //bfs
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(gardenCopied[i][j] == RED || gardenCopied[i][j] == GREEN){
                gardenNode g;
                g.x = j;
                g.y = i;
                g.day = 0;
                g.color = gardenCopied[i][j];
                node_q.push(g);
            }
        }
    }
    
    int cnt = 0;
    while(node_q.empty() == false){
        gardenNode cur = node_q.front();
        node_q.pop();
        
        if(gardenCopied[cur.y][cur.x] == FLOWER){ continue; }
        
        for(int i = 0; i < 4; i++){
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            
            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if(gardenCopied[y][x] == WHITE || gardenCopied[y][x] == BROWN){
                gardenNode next;
                next.x = x;
                next.y = y;
                next.color = cur.color;
                next.day = cur.day + 1;
                visDay[y][x] = cur.day + 1;
                gardenCopied[y][x] = cur.color;
                node_q.push(next);
            }else if((gardenCopied[y][x] == GREEN && cur.color != GREEN) ||
                (gardenCopied[y][x] == RED && cur.color != RED)){
                    if(visDay[y][x] == cur.day + 1){
                        // cout << "(x, y) :: "<< x << ", " << y << "\n";
                        gardenCopied[y][x] = FLOWER;
                        cnt++;
                    }
            }
        }
    }
    
   return cnt;
}

bool selected[2500];
int dfs(int n, int m, int g, int r, int curG, int curR, int start){

    //cout << "called : "<< ++called << "\n";
    if(curG == g && curR == r){
        return bfs(n, m);
    }
    
    int maxValue = 0;
    for(int i = start; i < browns.size(); i++){
        auto pos = browns[i];
        if(selected[i]) continue;
        if(g > curG){
            selected[i] = true;
            garden[pos.second][pos.first] = GREEN;
            maxValue = max(maxValue, dfs(n, m, g, r, curG + 1, curR, i));
            garden[pos.second][pos.first] = BROWN;
            selected[i] = false;
        }
        
        if(r > curR){
            selected[i] = true;
            garden[pos.second][pos.first] = RED;
            maxValue = max(maxValue, dfs(n, m, g, r, curG, curR + 1, i));
            garden[pos.second][pos.first] = BROWN;
            selected[i] = false;
        }
    }
    return maxValue;
}

int main()
{
    int n, m, g, r;
    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> garden[i][j];
            
            if(garden[i][j] == BROWN){
                browns.push_back({j, i});
            }
        }
    }
    cout << dfs(n,m,g,r,0,0,0);
    return 0;
}
