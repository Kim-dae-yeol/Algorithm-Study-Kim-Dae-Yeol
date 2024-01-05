
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    int x, y, time;
}node;


int n;
int sea[20][20];
int dx[4]{0, -1, 1, 0};
int dy[4]{-1, 0, 0, 1};
const int SHARK = 9;
const int BLANK = 0;
node start;
bool vis[20][20];
vector<node> founds;

void bfs(){
    int sharkSize = 2;
    int food = 0;
    int time = 0;
    queue<node> node_q;
    vis[start.y][start.x] = true;
    node_q.push(start);
    
    do{
        int fishX = 9999;
        int fishY = 9999;
        int curTime = 0;
        for(const auto& fish : founds){
            if(fishY > fish.y){
                
                fishX = fish.x;
                fishY = fish.y;
                curTime = fish.time;
            }else if(fishY == fish.y && fishX > fish.x){
                fishX = fish.x;
                fishY = fish.y;
                curTime = fish.time;
            }
        }
        
        //Set position for next Searching
        if(founds.empty() == false){
            founds.clear();
            node cur;
            cur.x = fishX;
            cur.y = fishY;
            cur.time = curTime;
            time = cur.time;
            food++;
            food %= sharkSize;
            if(!food) sharkSize++;
            sea[cur.y][cur.x] = BLANK;
            
            //RESET
            for(int i = 0; i < n; i++)
                fill(vis[i], vis[i] + n, false);
            node_q.push(cur);
        }
        
        bool found = false;
        int dist = 99999;
        
        while(node_q.empty() == false){
            //Searching...
            node cur = node_q.front();
            node_q.pop();
            
            for(int i = 0; i < 4; i++){
                int x = cur.x + dx[i];
                int y = cur.y + dy[i];
                if(x < 0 || x >= n || y < 0 || y >= n || sea[y][x] > sharkSize || vis[y][x]) continue;
                
                vis[y][x] = true;
                node nxt;
                nxt.x = x;
                nxt.y = y;
                nxt.time = cur.time + 1;
                
                //Found !!
                if(sea[y][x]!= BLANK && sea[y][x] < sharkSize && nxt.time <= dist){
                    found = true;
                    dist = nxt.time;
                    founds.push_back(nxt);
                }else if(!found){
                    node_q.push(nxt);
                }
            }
        }
    }while(!founds.empty());
    cout << time;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> sea[i][j];
            if(sea[i][j] == SHARK) {
                sea[i][j] = BLANK;
                start.x = j;
                start.y = i;
                start.time = 0;
            }
        }
    }
    
    bfs();
    return 0;
}
