
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int mat[301][301];
int n,m,r;
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};

void rotate(){
    pair<int, int> lo{0, 0};
    pair<int, int> hi{n - 1, m - 1};
    while(lo < hi){
        auto cur = lo;
        int prevValue;
        prevValue = mat[cur.first][cur.second];
        
        for(int i = 0; i < 4; i++){
            bool isEdge = false;
            do{
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if(nx < lo.second || nx > hi.second || ny < lo.first || ny > hi.first) break;
                cur.first = ny; 
                cur.second = nx;
                
                auto tmp = prevValue;
                prevValue = mat[cur.first][cur.second];
                mat[cur.first][cur.second] = tmp;
                
                if(i % 2 == 0){
                    isEdge = cur.first == lo.first || cur.first == hi.first;
                }else {
                    isEdge = cur.second == lo.second || cur.second == hi.second;
                }
            }while(isEdge == false);
        }
        lo.first++;
        lo.second++;
        hi.first--;
        hi.second--;
    }
}

void print_mat(){
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> mat[i][j];
        }
    }
    
    while(r--){
        // cout << "=================\n";
        rotate();
        // print_mat();
        // cout << "=================\n";
    }
    print_mat();
    return 0;
}










