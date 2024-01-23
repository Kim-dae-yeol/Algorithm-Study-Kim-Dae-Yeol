// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int invisible = 0;
int n, m;
int map[9][9];
bool vis[4][9][9];
bool light[9][9];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

int bfs(vector<tuple<int, int, int>>& cam){
    queue<tuple<int, int, int>> q; // curPos, cur dir
    
    for(const auto& e : cam){
        int r,c,cnum,dir;
        tie(r,c,dir) = e;
        cnum = map[r][c];
        
        switch(cnum){
            case 1:
            q.push({r,c,dir});
            break;
            case 2: 
            q.push({r,c,dir});
            q.push({r,c,(dir - 2 + 4)%4});
            break;
            case 3 : 
            q.push({r,c,dir});
            q.push({r,c,(dir - 1 + 4)%4});
            break;
            case 4 : 
            q.push({r,c,dir});
            q.push({r,c,(dir - 1 + 4) % 4});
            q.push({r,c,(dir - 2 + 4) % 4});
            break;
            case 5 : 
            q.push({r,c,dir});
            q.push({r,c,(dir +1) % 4});
            q.push({r,c,(dir +2) % 4});
            q.push({r,c,(dir +3) % 4});
            break;
        }
        
    }
    
    int cnt = 0;
    while(q.empty() == false){
        auto cur = q.front(); q.pop();
        //TODO 카메라종류 + 방향에 따라서 bfs 서칭 실행
        int curR,curC,curD;
        tie(curR,curC,curD) = cur;
        int nr = curR + dy[curD];
        int nc = curC + dx[curD];
        
        if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
        if(map[nr][nc] == 6 || vis[curD][nr][nc]) continue;
        if(map[nr][nc] == 0 && !light[nr][nc])
            cnt++;
        light[nr][nc] = true;
        vis[curD][nr][nc] = true;
        q.push({nr, nc, curD});
    }
    // cout<<"in bfs cnt :: " << cnt << "\n";
    return cnt;
}

int dfs(vector<tuple<int, int, int>>& cam, int idx){
    // cout << "dfs : "<< idx << "\n";
    
    if(idx >= cam.size()) {
        // cout << "bfs" << "\n";
        for(int i = 0; i < 4; i++){
            for(int j = 0 ; j < n; j++){
                fill(light[j], light[j] + m + 1 , false);
                fill(vis[i][j], vis[i][j] + m + 1 , false);
            }
        }
        return invisible - bfs(cam);
    }
    
    int ret = 1000000;
    auto& cur = cam[idx];
    int r,c,dir;
    tie(r, c, dir) = cur;
    
    for(int i = 0; i < 4; i++){
        if(map[r][c] == 5) {
            ret = min(ret, dfs(cam, idx + 1));
            break;
        }
        get<2>(cur) = i;
        ret = min(ret, dfs(cam, idx + 1));
    }
    
    return ret;
}

int main()
{
    cin >> n >> m;
    invisible = n * m;
    vector<tuple<int, int, int>> cam;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if( map[i][j] == 6){
                invisible--;
            }
            else if(map[i][j]){
                //CAMERA
                invisible--;
                cam.push_back({i, j, 0});
            }
        }
    }
    cout << dfs(cam, 0);
    return 0;
}
