#include <bits/stdc++.h>
using namespace std;
int main(){
    string hex;
    cin >> hex;
    int r = hex.length() - 1;
    int sum = 0;
    int m = 1;
    while(r >= 0){
        if(hex[r] > '9'){
            sum += m * (hex[r] - 'A' + 10);
        }else {
            sum += m * (hex[r] - '0');
        }
        m *= 16;
        r--;
    }
    cout << sum;
    return 0;
}