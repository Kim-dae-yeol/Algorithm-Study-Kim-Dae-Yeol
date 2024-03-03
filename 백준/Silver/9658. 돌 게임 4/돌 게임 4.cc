#include <bits/stdc++.h>
using namespace std;
int cached[1001];

int main(){
    int n;
    cin >> n;
    
    cached[0] = true;
    cached[1] = false;
    for(int i = 2; i<= n; i++){
        cached[i] = cached[i] || !cached[i - 1];
        if(i - 3 >= 0) {
            cached[i] = cached[i] || !cached[i - 3];
        }
        
        if(i - 4 >= 0){
            cached[i] = cached[i] || !cached[i - 4];
        }
    }
    cout << (cached[n] ? "SK" : "CY");
    return 0;
}