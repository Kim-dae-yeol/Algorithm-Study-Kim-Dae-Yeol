
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;
int n, m;
string s[51];
bool vis[11][11][11][11]; 
int dx[4]{0,1,0,-1};
int dy[4]{-1, 0, 1, 0};
queue<tuple<int, int, int, int, int>> q;
bool lean(int i, pair<int, int>& r,  pair<int, int>& b){
    pair<bool, bool> isOnWhole;
    //첫번째 이동으로 앞서나가는 돌이 있으면 멈추도록
    while(r.first > 0 && r.second > 0 && r.first < n-1 && r.second < m-1){
        int nr = r.first + dy[i];
        int nc = r.second + dx[i];
        if((s[nr][nc] != '.' && s[nr][nc] != 'O') ) break;
        if((nr == b.first && nc == b.second) && s[nr][nc] != 'O') break; 
        r.first = nr;
        r.second = nc;
        if(s[nr][nc] == 'O'){isOnWhole.first = true; break;}
    }
    while(b.first > 0 && b.second >  0 && b.first < n-1 && b.second < m-1){
        int nr = b.first + dy[i];
        int nc = b.second + dx[i];
        if((s[nr][nc] != '.' && s[nr][nc] != 'O')) break;
        if((nr == r.first && nc == r.second) && s[nr][nc] != 'O') break; 
        b.first = nr;
        b.second = nc;
        if(s[nr][nc] == 'O'){return false;}
    }
    
    while(!isOnWhole.first && r.first > 0 && r.second > 0 && r.first < n-1 && r.second < m-1){
        int nr = r.first + dy[i];
        int nc = r.second + dx[i];
        if(s[nr][nc] == '#') break;
        if(( nr == b.first && nc == b.second) && s[nr][nc] != 'O') break;
        r.first = nr;
        r.second = nc;
        isOnWhole.first = (s[nr][nc] == 'O');
    }
    while(!isOnWhole.second && b.first > 0 && b.second > 0 && b.first < n - 1 && b.second < m - 1){
        int nr = b.first + dy[i];
        int nc = b.second + dx[i];
        if(s[nr][nc] == '#') break;
        if(( nr == r.first && nc == r.second) && s[nr][nc] != 'O') break;
        b.first = nr;
        b.second = nc;
        isOnWhole.second = (s[nr][nc] == 'O');
    }
    
    //이동이 끝난 지점이 방문 했으면 false
    return !vis[r.first][r.second][b.first][b.second];
}

int main()
{
    pair<int, int> rPos;
    pair<int, int> bPos;
    pair<int, int> dPos;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> s[i];
        for(int j = 0 ; j < m; j++){
            if(s[i][j] == 'R'){
                s[i][j] = '.';
                rPos.first = i;
                rPos.second = j;
            }else if(s[i][j] == 'B'){
                s[i][j] = '.';
                bPos.first = i;
                bPos.second = j;
            }else if(s[i][j] == 'O'){
                dPos.first = i;
                dPos.second = j;
            }
        }
    }
    
    
    q.push({rPos.first, rPos.second, bPos.first, bPos.second, 0});
    vis[rPos.first][rPos.second][bPos.first][bPos.second] = true;
    bool isEnd = false;
    while(q.empty() == false){
        auto cur = q.front(); q.pop();
        pair<int, int> red, blue;
        int cnt;
        tie(red.first, red.second, blue.first, blue.second, cnt) = cur;
        if(cnt > 10) { cout << -1 << "\n"; isEnd=true; break;}
        if(red.first == dPos.first && red.second == dPos.second) {
            cout << cnt;
            isEnd = true;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            pair<int, int> red_simul, blue_simul;
            red_simul = red;
            blue_simul = blue;
            if(lean(i, red_simul, blue_simul)){
                // cout << "===AFTER SIMULATE==="<<"\n";
                // for(int j = 0; j < n; j ++){
                //     for(int k = 0; k < m; k++){
                //         if(j == red_simul.first && k == red_simul.second){ cout << "R"; continue;}
                //         if(j == blue_simul.first && k == blue_simul.second){ cout << "B"; continue;}
                //         cout << s[j][k];
                //     }
                //     cout << "\n";
                // }
                // cout << "===AFTER SIMULATE==="<<"\n";
                
                vis[red_simul.first][red_simul.second][blue_simul.first][blue_simul.second] = true;
                q.push({red_simul.first, red_simul.second, blue_simul.first, blue_simul.second, cnt+1});
            }
            
            
        }
        
    }
    if(!isEnd) cout << -1;
}
