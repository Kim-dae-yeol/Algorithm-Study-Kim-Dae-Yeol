
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;
int coin[100001];
int n;
int main()
{
    coin[0] = 0;
    coin[1] = -1;
    cin >> n;
    for(int i = 2; i <= n; i++){
        coin[i] = -1;
        
        if(i - 5 >= 0 && coin[i - 5] >= 0){
            coin[i] = coin[i - 5] + 1;
        }
        
        if(coin[i-2] >= 0 && (coin[i - 2] + 1 < coin[i] || coin[i] == -1) ){
            coin[i] =coin[i - 2] + 1;
        }
    }
    
    cout << coin[n];
    return 0;
}
