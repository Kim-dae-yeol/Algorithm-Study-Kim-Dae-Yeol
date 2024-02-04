
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>

using namespace std;
int price[1001];
int n;
int max_price[1001];
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> price[i];
        
    max_price[0] = 0;
    for(int i = 1; i <= n; i++){
        max_price[i] = 0;
        for(int j = 0; j <= i; j++){
            max_price[i] = max(price[j] + max_price[i - j], max_price[i]);
        }
    }
    
    cout << max_price[n];
    return 0;
}
