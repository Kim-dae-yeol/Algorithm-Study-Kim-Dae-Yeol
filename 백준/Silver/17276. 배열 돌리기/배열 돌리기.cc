#include<bits/stdc++.h>
using namespace std;

int t,n;
int prev_line[500];
int tmp_swap[500];
int matrix[500][500];
//주대각 - 가운데 열 - 부대각 - 가운데 행
int startX[4];
int startY[4];
int dx[4]{1, 0, 1, 1};
int dy[4]{1, 1, -1, 0};
//1 5 45 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
//1 5 -45 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
void print_matrix();

void rotate(int deg){
    // deg %= 360;
    int cnt = deg / 45;
    int dir = cnt > 0 ? 1 : -1;
    if(cnt < 0) {
        cnt *= -1;
    }
    
    for(int i = 0 ; i < cnt; i++){
        for(int j = 0; j < n; j++){
            int x = startX[0] + dx[0] * j;
            int y = startY[0] + dy[0] * j;
            prev_line[j] = matrix[y][x];
        }
        
        for(int j = 1; j <= 4; j++){
            int cur = j * dir + 4;
            cur %= 4;
            
            for(int k = 0; k < n; k++){
                int x = startX[cur] + dx[cur] * k;
                int y = startY[cur] + dy[cur] * k;
                
                tmp_swap[k] = matrix[y][x];
                matrix[y][x] = prev_line[k];
                
            }
            
            for(int k = 0; k < n; k++){
                if((cur == 1 && dir == 1) || (cur == 2 && dir == -1)){
                    prev_line[n - 1 - k] = tmp_swap[k];
                }else {
                    prev_line[k] = tmp_swap[k];
                }
            }
        
        }
    }
}

void print_matrix(){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    
    cin >> t;
    while(t--){
        int deg;
        cin >> n >> deg;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        
        startX[1] = n / 2;
        startY[2] = n - 1;
        startY[3] = n / 2;
        rotate(deg);
        print_matrix();
    }
}



