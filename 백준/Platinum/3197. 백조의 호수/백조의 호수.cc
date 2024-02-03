#include<bits/stdc++.h>
using namespace std;
int r, c;
string lake[1505];
pair<int, int> par[1505][1505];
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};
bool vis[1505][1505];
pair<int, int> find(pair<int, int> a){
    if(par[a.first][a.second] == a) return a;
    return par[a.first][a.second] = find(par[a.first][a.second]);
}

bool u(pair<int, int> a, pair<int, int> b){
    a = find(a); b = find(b);
    if(a == b) return true;
    
    if(a < b){
        par[b.first][b.second] = a;
    }else {
        par[a.first][a.second] = b;
    }
    return false;
}

int main(){
    //1. 녹인다.
    //2. 녹인 부분을 분리집합으로 관리한다.
    //3. 두 오리가 있는 물의 분리집합이 하나의 집합으로 합쳐지면 종료
    cin >> r >> c;
    queue<tuple<int, int, int>> q;
    pair<int, int> pos1;
    pair<int, int> pos2;
    
    pos1.first = -1;
    
    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j <c; j++){
            par[i][j] = {i, j};
        }
    }
    
    for(int i = 0 ; i < r; i++){
        cin >> lake[i];
        for(int j = 0; j < c; j++){
            if(lake[i][j] == '.'){
                //물
                q.push({i,j,0});
            }
            if(lake[i][j] == 'L'){
                //백조
                q.push({i,j,0});
                
                if(pos1.first == -1 ){
                    pos1.first = i;
                    pos1.second = j;
                }else {
                    pos2.first = i;
                    pos2.second = j;
                }
            }
        }
    }
    
    int result = 0;
    stack<pair<pair<int, int>, pair<int, int>>> nextWater;
    
    while(true){
        while(q.empty() == false){
            auto cur = q.front(); q.pop();
            int curR,curC,curDay;
            tie(curR,curC,curDay) = cur;
            
            for(int i = 0 ; i < 4; i++){
                int nr = curR + dy[i];
                int nc = curC + dx[i];
                
                if(nr >= r || nr < 0 || nc >= c || nc < 0 )continue;
                
                if(lake[nr][nc] == 'X'){
                    if(vis[nr][nc] == false){
                        vis[nr][nc] = true;
                        nextWater.push({{nr,nc}, {curR, curC}});
                    }
                }else{
                    if(u({curR, curC}, {nr, nc}) == false){
                        q.push({nr, nc, curDay});
                    }
                }
                
            }
        }
        
        auto par1 = find(pos1);
        auto par2 = find(pos2);
        
        if(par1 == par2){
            break;
        }
        
        result ++;
        while(nextWater.empty() == false){
            auto water = nextWater.top(); nextWater.pop();
            auto cur = water.first;
            u(cur, water.second);
            lake[cur.first][cur.second] = '.';
            q.push({cur.first, cur.second, result});
        }
        
    }
    
    cout << result;
}


