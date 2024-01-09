
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
// #include<pair>

using namespace std;
int n, k;

int board[3][3];
bool vis[3][3];

void bfs(){
    queue<pair<int, int>> q;
    q.push({0,0});
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        
        if(cur.first == n - 1 && cur.second == n-1){
            cout << "HaruHaru";
            return;
        }
        
        int x = cur.first;
        int y = cur.second;
        
        int value = board[x][y];
        
        if(x + value < n && board[x + value][y]){
            q.push({x + value, y});
        }
        
        if(y + value < n && board[x][y + value]){
            q.push({x, y + value});
        }
    }
    
    cout << "Hing"; 
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    bfs();
    return 0;
}
