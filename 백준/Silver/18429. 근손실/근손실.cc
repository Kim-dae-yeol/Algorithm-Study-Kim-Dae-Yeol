#include<iostream>
#include<vector>

using namespace std;
int n, k;
int kits[8];
bool vis[8];
int ret = 0;
void dfs(int weight, int cnt){
    if(cnt == n){
        ret ++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        
        if(weight + kits[i] - k >= 500){
            vis[i] = true;
            dfs(weight + kits[i] - k, cnt + 1);
            vis[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i< n; i++){
        cin >> kits[i];
    }
    
    dfs(500, 0);
    cout << ret;
}