
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int n, m;
long long k;
int board[21][21];
pair<int, int> dest[405];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};
bool vis[21][21];


void clear_vis(){
    for(int i = 0 ; i <= n; i++)
        fill(vis[i], vis[i] + n + 1, false);
}

// 1. 위치로 -> 남은 승객이 없으면 종료 
// 2. 최단거리 승객찾기(BFS) -> 태울 수 없으면 종료 -1 
// 3. 승객 태우고 오기 (BFS) -> 도착 불가능 하면 -1
// 4. (1.) 로 돌아가 반복한다.
int bfs(int r,int c){
    int cnt = 0;
    while(cnt < m) {
        queue<tuple<int, int, long long>> q;
        q.push({r, c, k});
        bool found = false;
        vector<pair<int, int>> adjPas;
        clear_vis();
        int foundK = -1;
        while(q.empty() == false){
            //BFS를 통해서 최단거리의 승객을 모두 찾는다.
            auto cur = q.front(); q.pop();
            int curR,curC;
            long long curK;
            tie(curR, curC, curK) = cur;
            if(board[curR][curC] > 1){
                found = true;
                k = curK;
                foundK = k;
                adjPas.push_back({curR, curC});
                continue;
            }
            if(curK == 0) continue;
            
            for(int i = 0; i < 4; i++){
                int nr = curR + dy[i];
                int nc = curC + dx[i];
                
                if(nr >= n || nr < 0 || nc >= n || nc < 0 ) continue;
                if(board[nr][nc] == 1) continue;
                if(vis[nr][nc]) continue;
                
                
                if(board[nr][nc] > 1 && curK - 1 >= foundK){
                    found = true;
                    k = curK - 1;
                    foundK = k;
                    // cout << "find passenger::"  << nr << ", " << nc << "::" << k << endl;
                    adjPas.push_back({nr, nc});
                }else if(board[nr][nc] == 0 && !found){
                    vis[nr][nc] = true;
                    q.push({nr, nc, curK - 1});
                }
            }
        }
        
        if(!found) return -1; //최단거리의 승객에 도달 할 수 없다.
        int minR, minC, idx;
        minR = minC = 99999;
        for(int i = 0; i < adjPas.size(); i++){
            auto e = adjPas[i];
            if(minR > e.first){
                idx = i;
                minR = e.first;
                minC = e.second;
            }else if(minR == e.first && minC > e.second){
                idx = i;
                minR = e.first;
                minC = e.second;
            }
        }
        

        auto pos = adjPas[idx];
        // cout << cnt + 1 << "-depart::" << pos.first << ", "<< pos.second << endl;
        int destIdx = board[pos.first][pos.second];
        board[pos.first][pos.second] = 0; // 승객 위치를 블록으로 초기화
        // cout << "destIdx" << destIdx << endl;
        auto destInfo = dest[destIdx];
        // cout << cnt + 1 << "-dest::" << destInfo.first << ", " <<destInfo.second << endl;
        
        queue<tuple<int, int, long long, int>> dropQ;
        clear_vis();
        dropQ.push({pos.first, pos.second, k, 0});
        bool canArrive = pos.first == destInfo.first && pos.second == destInfo.second;
        int dist = 0;
        while(dropQ.empty() == false && !canArrive){
            auto cur = dropQ.front(); dropQ.pop();
            int curR,curC,curD;
            long long curK;
            tie(curR,curC,curK,curD) = cur;
            if(curK == 0) continue;
            
            for(int i = 0; i < 4; i++){
                int nr = curR + dy[i];
                int nc = curC + dx[i];
                
                if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
                if(vis[nr][nc])continue;
                if(board[nr][nc] == 1) continue;
                
                if(nr == destInfo.first && nc == destInfo.second) {
                    dist = curD + 1;
                    canArrive = true;
                    r = nr;
                    c = nc;
                    k = curK - 1;
                    break;
                }
                
                vis[nr][nc] = true;
                dropQ.push({nr, nc, curK - 1, curD + 1});
            }
        }
        
        if(!canArrive) return -1;
            
        cnt ++;
        k += dist * 2;
    }
    
    return k;
}

int main()
{
    cin >> n >> m >> k;
    int r, c;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j ++){
            cin >> board[i][j];
        }
    }
    
    
    cin >> r >> c;
    r--;
    c--;
    for(int i = 2; i < m + 2 ; i++){
        int startR, startC, destR, destC;
        cin >> startR >> startC >> destR >> destC;
        dest[i] = {destR - 1, destC - 1};
        board[startR-1][startC-1] = i;
        //저장된 i 를 통해서 도착지 배열에 접근 
    }
    // cout << "=====Map=====" << endl;
    // for(int i = 0 ; i < n; i++){
    //     for(int j = 0 ; j < n; j ++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << bfs(r, c);
}
