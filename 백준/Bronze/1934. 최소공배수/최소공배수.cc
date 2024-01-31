#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    return a%b == 0 ? b : gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a * b / gcd(a,b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b)<<"\n";
    }
}