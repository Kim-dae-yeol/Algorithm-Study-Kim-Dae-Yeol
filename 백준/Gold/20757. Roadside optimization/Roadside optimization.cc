// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int p[205];
int adj[205][205];

int find(int u){
    if(p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}

bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return false;
    
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            p[i] = i;
            for(int j = 1; j <= n; j++){
                cin >> adj[i][j];
            }
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] && is_diff_group(i, j)) {
                    cnt ++;
                }
            }
        }
        cout << cnt << "\n";
    }
}
