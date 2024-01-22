
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
    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if((a && b && c ) == false){
            break;
        }
        
        a = a * a;
        b = b * b;
        c = c * c;
        
        int rest = b + c;
        int hypo = a;
        
        if(hypo < b) {
            hypo = b;
            rest = a + c;
        }
        
        if(hypo < c) {
            hypo = c;
            rest = a + b;
        }
        // 900000000
        cout << (rest == hypo ? "right": "wrong") <<"\n";
    }
}
