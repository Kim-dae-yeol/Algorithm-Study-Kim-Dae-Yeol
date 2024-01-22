
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int cnt[15][15];

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> k >> n;
        //a - b
        //계약 조항 : a , b에 살ㄹ려면 전의 층의 사람들을 데려와 살아야 한다.
        //0층 to i 층
        //k 층 n 호에 몇명이 살고있는지?? 
        
        //0층 i호에는 i명이 산다 
        //1층 i호는 sum 1 .. i;
        for(int i = 0 ; i <= k; i++){
            for(int j = 1; j <= n; j++){
                if(i == 0) cnt[i][j] = j;
                else {
                    cnt[i][j] = 0;
                    for(int kk = 1; kk <= j; kk++){
                        cnt[i][j] += cnt[i - 1][kk];
                    }
                }
            }
        }
        cout << cnt[k][n] << "\n";
    }
    return 0;
}
