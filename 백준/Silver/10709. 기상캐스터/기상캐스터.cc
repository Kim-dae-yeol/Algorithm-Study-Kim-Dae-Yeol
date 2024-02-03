
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<utility>

using namespace std;
int w, h;
string s[101];
int result[101][101];
queue<pair<pair<int,int>, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> h >> w;
    
    for(int i = 0 ; i < h; i++)
        fill(result[i], result[i] + w, -1);
    
    for(int i = 0; i < h; i++){
        cin >> s[i];
        for(int j = 0 ; j < w; j++){
            if(s[i][j] == 'c'){
                q.push({{i, j}, 0});
                result[i][j] = 0;
            }
        }
    }
    
    
    
    while(q.empty()== false){
        auto cur = q.front(); q.pop();
        auto pos = cur.first;
        auto ret = cur.second;
        int nx = pos.second + 1;
        
        if(nx < 0 || nx >= w) continue;
        if(result[pos.first][nx] >= 0) continue;
        
        q.push({{pos.first, nx}, ret + 1});
        result[pos.first][nx] = ret + 1;
    }
    
    for(int i = 0 ; i < h; i++){
        for(int j = 0 ; j < w; j++){
            cout << result[i][j] <<" "; 
        }
        cout << "\n";
    }
    return 0;
}
