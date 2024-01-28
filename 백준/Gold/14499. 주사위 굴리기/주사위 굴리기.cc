#include<bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int dice1[4]; // east top west bot
int dice2[4]; // south top north bot
int dx[4]{0, 0, -1, 1};
int dy[4]{1, -1, 0, 0};
int map_num[20][20];
vector<int> cmd;
const int top = 1;
const int bot = 3;


void roll_dice(int e){
    if(e <= 2){
        int delta = (e % 2 ? 1 : -1);
        int first_tmp = dice1[0];
        int idx = 0;
        for(int i = 0 ; i < 3; i++){
            int nxt = idx;
            nxt += delta + 4;
            nxt %= 4;
            dice1[idx] = dice1[nxt];
            idx = nxt;
        }
        dice1[idx] = first_tmp;
        dice2[top] = dice1[top];
        dice2[bot] = dice1[bot];
    } else {
        int delta = (e % 2 ? 1 : -1);
        int first_tmp = dice2[0];
        int idx = 0;
        for(int i = 0 ; i < 3 ; i++){
            int nxt = idx;
            nxt += delta + 4;
            nxt %= 4;
            dice2[idx] = dice2[nxt];
            idx = nxt;
            dice2[idx] = first_tmp;
        }
        dice2[idx] = first_tmp;
        dice1[top] = dice2[top];
        dice1[bot] = dice2[bot];
    }
}

void print(){
    cout << "====dice====\n";
    cout << "top bottom east west south north \n" ;
    cout << dice1[top] << " " <<  dice1[bot] << " " << dice1[0] << 
    " " << dice1[2] << " " << dice2[0] << " " << dice2[2] <<"\n";
    cout << "====dice====\n";
    cout << "======map======\n";
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ;j ++){
            cout << map_num[i][j] <<" ";
        }
        cout << "\n";
    }
    cout << "======map======\n";
}

int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> map_num[i][j];
        }
    }
    
    for(int i = 0 ; i < k; i++){
        int cmd_ele;
        cin >> cmd_ele;
        cmd.push_back(cmd_ele);
    }
    
    for(auto e : cmd){
        // cout << x << ", "<< y << " - COMMAND :: " << e << "\n";
        int nx = x + dx[e - 1];
        int ny = y + dy[e - 1];
        if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        x = nx;
        y = ny;
        //주사위 굴리기
        roll_dice(e);
        
        if(map_num[nx][ny]){
            //바닥 숫자를 주사위에 옮김
            dice1[bot] = dice2[bot] = map_num[nx][ny];
            map_num[nx][ny] = 0;
        }else {
            //주사위 숫자를 바닥에 씀
            map_num[nx][ny] = dice1[bot];
        }
        
        // print();
        cout << dice1[top] << "\n";
    }
}