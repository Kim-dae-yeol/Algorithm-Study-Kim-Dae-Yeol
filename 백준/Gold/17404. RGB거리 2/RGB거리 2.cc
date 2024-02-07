#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1001][3][3]; // [idx][cur_color][first_color]
int price[1001][3];
void print_dp_table(){
    for(int i = 0 ; i < n; i++){
        cout << "======\n";
        for(int j = 0 ; j <3; j++){
            for(int k = 0 ; k < 3; k++){
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "======\n";
    }
}
int main(){
    cin >> n;
    for(int i = 0 ; i <n; i++){
        for(int j = 0 ; j <3; j++){
            cin >> price[i][j];
        }
    }
    
    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(i == 0 && j == k){
                    dp[i][j][k] = price[i][j];
                }else if((i == n - 1 && j == k) || (i == 0 && j != k)){
                    dp[i][j][k] = INT_MAX;
                }else {
                    // r g b
                    int prev = j - 1 + 3;
                    int next = j + 1 + 3;
                    prev %= 3;
                    next %= 3;
                    dp[i][j][k] = min(dp[i - 1][prev][k], dp[i - 1][next][k]);
                    if(dp[i][j][k] == INT_MAX) {
                        continue;
                    }
                    dp[i][j][k] += price[i][j];
                }
            }
        }
    }
    //13 40 57 = 70 + 40 = 110
    
    int min_price = dp[n-1][0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            min_price = min(dp[n-1][i][j], min_price);
        }
    }
    
    cout << min_price;
    // print_dp_table();
}