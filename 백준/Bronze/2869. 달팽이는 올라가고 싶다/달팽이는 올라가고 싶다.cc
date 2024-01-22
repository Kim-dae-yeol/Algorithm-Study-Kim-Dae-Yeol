
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a,b,v;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> a >> b >> v;
    int result = ((v - b) / (a - b)) + ((v - b) % (a - b) ? 1 : 0 ) ;
    cout << result;
    return 0;
}
