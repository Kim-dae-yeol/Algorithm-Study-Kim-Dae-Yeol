#include<bits/stdc++.h>

using namespace std;
int dx[4]{0,1,0,-1};
int dy[4]{-1,0,1,0};
int che_mat[101][101];
int n, m;
bool vis[101][101];

void print_cheese(){
    cout << "==========cheese=========\n";
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            if(che_mat[i][j]) 
                cout << che_mat[i][j] <<" ";
            else 
                cout << " " <<" ";
        }
        cout <<"\n";
    }
    cout << "==========cheese=========\n";
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> che_mat[i][j];
        }
    }
    
    queue<pair<int, int>> airQ;
    queue<pair<int, int>> cheeseQ;
    vector<pair<int, int>> cheese_list;
    
    airQ.push({0, 0});
    int cheese = 0;
    int day = 0;
    
    while(airQ.empty()==false){
        auto cur = airQ.front(); airQ.pop();
        for(int i = 0; i <4; i ++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            
            vis[ny][nx] = true;
            if(che_mat[ny][nx]) cheese_list.push_back({nx, ny});
            else airQ.push({nx, ny});
        }
    }
    
    while(cheese_list.empty() == false){
        // print_cheese();
        cheese = cheese_list.size();
        for(auto e : cheese_list){
            airQ.push(e);
            che_mat[e.second][e.first] = 0;
        }
        day++;
        cheese_list.clear();
        
        while(airQ.empty()==false){
            auto cur = airQ.front(); airQ.pop();
            for(int i = 0; i < 4; i ++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(vis[ny][nx]) continue;
                
                vis[ny][nx] = true;
                if(che_mat[ny][nx]) cheese_list.push_back({nx, ny});
                else airQ.push({nx, ny});
            }
        }
    }
    
    cout << day << "\n";
    cout << cheese;
}











