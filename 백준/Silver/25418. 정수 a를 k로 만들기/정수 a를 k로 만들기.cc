
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
// #include<pair>

using namespace std;
int n, k;
bool vis[1000001];

void bfs(){
    queue<pair<int, int>> q;
    q.push({n, 0});
    int result = 0;
    
    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        
        if(cur.first == k){
            result = cur.second;
            break;
        }
        
        int nxt1 = cur.first + 1;
        int nxt2 = cur.first * 2;
        
        if(nxt1 <= k && !vis[nxt1]){
            vis[nxt1] = true;
            q.push({nxt1, cur.second + 1});
        }
        if(nxt2 <= k && !vis[nxt2]){
            vis[nxt2] = true;
            q.push({nxt2, cur.second + 1});            
        }
    }
    
    cout << result;
}

int main()
{
    cin >> n >> k;
    bfs();
    return 0;
}
