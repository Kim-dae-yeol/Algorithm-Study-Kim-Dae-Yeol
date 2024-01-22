
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a%b) return gcd(b, a % b);
    return b;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    cout << lcm(a, b) << "\n";
}
