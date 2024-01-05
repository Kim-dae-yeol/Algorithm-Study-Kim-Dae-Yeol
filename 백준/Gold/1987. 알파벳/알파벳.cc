
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
vector<string> board;

int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};
bool vis[26];
int n, m;

int dfs(int x, int y, int dist){
    // cout << "cur position : " << x << ", " << y << "\n";
    // cout << "cur dist : " << dist << "\n";
    int ret = dist;
    
    for(int i = 0; i < 4; i++){
        //Next position 
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        //Out of board
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        
        //Already visited 
        char nc = board[ny][nx];
        if(vis[nc - 'A']) continue;
        
        vis[nc - 'A'] = true;
        ret = max(ret, dfs(nx, ny, dist + 1));
        vis[nc - 'A'] = false;
    }
    
    return ret;
}


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        board.push_back(input);
    }
    
    vis[board[0][0] - 'A'] = true;
    cout << dfs(0, 0, 1);
    return 0;
}

