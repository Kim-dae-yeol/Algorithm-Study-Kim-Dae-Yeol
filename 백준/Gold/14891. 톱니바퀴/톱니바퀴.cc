
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;

int wheels[4][8];
int left_wheel = 6;
int right_wheel = 2;
int k;
bool vis[4];
void print_wheels(){
    for(int i = 0 ;i<4;i++){
        cout << i+1 << " :: ";
        for(int j = 0 ; j < 8 ;j++){
            cout << wheels[i][j];
        }
        cout << "\n";
    }
}
void rotate(int wheelNum, int dir){
    if(wheelNum > 0 && !vis[wheelNum - 1]){
        if(wheels[wheelNum][left_wheel] != wheels[wheelNum - 1][right_wheel]){
            vis[wheelNum - 1] = true;
            rotate(wheelNum - 1, dir * -1);
        }
    }
    
    if(wheelNum < 3 && !vis[wheelNum + 1]){
        if(wheels[wheelNum][right_wheel] != wheels[wheelNum + 1][left_wheel]){
            vis[wheelNum + 1] = true;
            rotate(wheelNum + 1, dir * -1);
        }
    }
    
    int idx = 0;
    int first = wheels[wheelNum][0];
    int prev = wheels[wheelNum][0];
    for(int i = 0 ; i < 7; i ++){
        int nxt = idx + dir;
        nxt += 8;
        nxt %= 8;
        int tmp = wheels[wheelNum][nxt];
        wheels[wheelNum][nxt] = prev;
        prev = tmp;
        idx = nxt;
    }
    
    wheels[wheelNum][0] = prev;
}

int main()
{
    for(int i = 0; i < 4; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < 8;j ++){
            wheels[i][j] = s[j] - '0';
        }
    }
    
    cin >> k;
    // print_wheels();
    while(k--){
        int num;
        int dir;
        cin >> num >> dir;
        fill(vis, vis + 4 , false);
        vis[num - 1] = true;
        rotate(num - 1, dir);
        // print_wheels();
    }
    
    int score = 0;
    for(int i = 0; i < 4; i++){
        score += wheels[i][0] * (1 << i);
    }
    cout << score;
    return 0;
}
