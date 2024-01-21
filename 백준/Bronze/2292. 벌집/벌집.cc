#include<iostream>

int n;
using namespace std;
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    int result = 1;
    long long cur = 1;
    while(cur < n){
        result ++;
        cur = cur + 6 * (result - 1);
    }
    
    cout << result;
}