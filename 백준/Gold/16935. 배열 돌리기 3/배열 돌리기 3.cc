#include<bits/stdc++.h>

using namespace std;

int n, m, r;
int mat[101][101];
int mat_tmp[101][101];
int mat_tmp_swap[101][101];

// 1. 배열 상하반전 
void invert_up_down(){
    int mid = n/2;
    for(int i = 0 ; i < mid; i++){
        for(int j = 0 ; j < m; j++){
            //swap i to n-i-1;
            int tmp = mat[i][j];
            mat[i][j] = mat[n-i-1][j];
            mat[n-i-1][j] = tmp; 
        }
    }
}

// 2. 배열 좌우반전
void invert_left_right(){
    int mid = m / 2;
    //열 우선 배열 탐색
    for(int i = 0; i < mid; i++){
        for(int j = 0 ; j < n; j++){
            int tmp = mat[j][i];
            mat[j][i] = mat[j][m - i - 1];
            mat[j][m - i - 1] = tmp;
        }
    }
}

// 3. 시계방향 90도 회전  + 4. 반시계방향 90도 회전 
void rotate(bool isRotationRight){
    int nn = m;
    int nm = n;
    
    //n과 m을 바꾼 후 열 우선탐색을 해서 열의 모든 원소를 1행으로 옮김 -> 시계방향으로
    for(int i = 0; i < m; i++){
        for(int j = 0 ; j < n; j++){
            int rowIdx = isRotationRight ? i : m - 1 - i;
            int colIdx = isRotationRight ? n - 1 - j : j;
            mat_tmp[rowIdx][colIdx] = mat[j][i];
        }
    }
    
    n = nn;
    m = nm;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            mat[i][j] = mat_tmp[i][j];
        }
    }
}


void group_rotate(bool isRotationRight){
    //시계방향만 만들고 변형시켜줌
    int midR = n / 2;
    int midC = m / 2;
    
    for(int i = 0 ; i < midR; i++){
        for(int j = 0 ; j < midC; j++){
            mat_tmp[i][j] = mat[i][j];
        }
    }
    int dir = isRotationRight ? 1 : -1;
    for(int k = 0; k < 4; k++){
        int gn = 0 + k * dir + 4 ;
        gn %= 4;
        int startR = gn < 2 ? 0 : midR;
        int startC = (gn < 1 || gn > 2 ) ? 0 : midC;
        
        for(int i = startR; i < startR + midR; i++){
            for(int j = startC; j < startC + midC; j++){
                
                 mat_tmp_swap[i-startR][j-startC] = mat[i][j];
                 mat[i][j] = mat_tmp[i-startR][j-startC];
                 mat_tmp[i-startR][j-startC] = mat_tmp_swap[i-startR][j-startC];
            }
        }
    }
    
    for(int i = 0 ; i < midR; i++){
        for(int j = 0 ; j < midC; j++){
            mat[i][j] = mat_tmp[i][j];
        }
    }
}

// 5. 6. 연산  -> 배열을 4사분면으로 나눈다.  -> 그룹을 시계방향으로 이동시킨다. 
//5 : 그룹의 이동을 시계방향으로 
//6 : 그룹의 이동이 반시계방향
//1 2
//4 3

void print_mat(){
    // cout << "===========print_mat========" << "\n"; 
    for(int i = 0 ; i <n; i++){
        for(int j = 0 ; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << "===========print_mat========" << "\n";
}

int main(){
    /*
    TC 1 : 4 4 1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 5
    */
    cin >> n >> m >> r;
    for(int i = 0 ; i <n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> mat[i][j];
        }
    }
    
    while(r--){
        int cmd;
        cin >> cmd;
        switch(cmd){
            case 1 : invert_up_down();
            break;
            case 2 : invert_left_right();
            break;
            case 3 : rotate(true);
            break;
            case 4 : rotate(false);
            break;
            case 5 : group_rotate(true);
            break;
            case 6 : group_rotate(false);
            break;
        }
        
        // print_mat();
    }
    print_mat();
    return 0;
}