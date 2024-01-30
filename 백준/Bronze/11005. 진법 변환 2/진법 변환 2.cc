#include<bits/stdc++.h>
using namespace std;
int n, b;
int main(){
    cin >> n;
    cin >> b;
    deque<char> d;
    while(n){
        int result = n % b;
        n /= b;
        if(result >= 10){
            result -= 10;
            d.push_front(result + 'A');
        }else {
            d.push_front(result + '0');
        }
    }
    for(auto e : d){
        cout << e;
    }
}