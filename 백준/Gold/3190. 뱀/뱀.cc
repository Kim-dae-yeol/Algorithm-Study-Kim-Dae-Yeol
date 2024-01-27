
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n,k;
int l;
bool apple[101][101];
deque<pair<int, int>> snake;
queue<pair<int, char>> cmd;
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};

void print(){
    cout << "================="<<'\n';
    for(int i = 1 ;i <= n ; i++){
        for(int j = 1 ; j <= n; j++){
            bool isSnake = false;
            for(auto e : snake){
                if(e.first == i && e. second == j){
                    cout << 'O';
                    isSnake = true;
                }
            }
            
            if(isSnake) continue;
            
            if(apple[i][j]){
                cout <<'A';
            }else {
                cout << '.';
            }
        }
        cout <<"\n";
    }
    cout << "================="<<'\n';
}
int main()
{
    cin >> n;
    cin >> k;
    for(int i = 0 ; i < k; i++){
        int r, c;
        cin >> r >> c;
        apple[r][c] = true;
    }
    cin >> l;
    for(int i = 0 ; i < l ;i++){
        int t;
        char c;
        cin >> t >> c;
        cmd.push({t, c});
    }
    
    bool isOver = false;
    int dir = 1;
    int t = 0;
    snake.push_front({1,1});
    while(isOver == false){
        t++;
        // print();
        int nr = snake.front().first + dy[dir];
        int nc = snake.front().second + dx[dir];
        
        if(nr <= 0 || nr > n || nc <= 0 || nc > n) {break;}
        for(auto e : snake){
            if(nr == e.first && nc == e.second){
                isOver = true;
                break;
            }
        }
        
        if(apple[nr][nc]){
            snake.push_front({nr, nc});
            apple[nr][nc] = false;
        }else {
            snake.push_front({nr, nc});
            snake.pop_back();
        }
        
        if(t == cmd.front().first){
            auto nxt = cmd.front().second;
            cmd.pop();
            if(nxt == 'L'){
                dir--;
                dir += 4;
                dir %= 4;
            }else if(nxt == 'D'){
                dir++;
                
                dir %= 4;
            }
        }
        
    }
    cout << t;
    return 0;
}
