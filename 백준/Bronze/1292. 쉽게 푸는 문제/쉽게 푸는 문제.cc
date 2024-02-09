
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int num = 1;
    int cnt = 0;
    for(int i = 1; i <= b; i++){
        if( i >= a)
            sum += num;
        cnt ++;
        if(cnt == num) {
            num ++;
            cnt = 0;
        }
    }
    cout << sum;
}