
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, m;
int broken[101][101];
vector<string> board;
int dx[4]{1,-1,0,0};
int dy[4]{0,0,1,-1};
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }
    for(int i = 0; i < m; i ++){
        fill(broken[i], broken[i] + n + 1, 10000000);
    }
    
    
    queue<tuple<int, int, int>> q;
    q.push({0,0,0});
    broken[0][0] = 0;
    

    while(q.empty()== false){
        
        auto cur = q.front(); q.pop();
        int x,y,cnt;
        tie(x,y,cnt) = cur;
        // cout << x << ", "<< y << "::" << cnt << "\n";
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            int ncnt = (board[ny][nx] == '0') ? cnt : cnt + 1;
            if(broken[ny][nx] <= ncnt) continue;
            
            broken[ny][nx] = ncnt;
            q.push({nx, ny, ncnt});
        }
    }
    
    cout << broken[m - 1][n - 1];
    return 0;
}





