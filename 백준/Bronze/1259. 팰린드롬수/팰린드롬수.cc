
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solution(const string& s){
    int l = 0;
    int r = s.length() - 1;
    while(l <= r){
        if(s[l] != s[r]){
            cout << "no" <<"\n";
            return;
        }
        l++; r--;
    }
    
    cout << "yes" << "\n";
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    while(true){
        string s;
        cin >> s;
        if(s == "0"){
            break;
        }
        solution(s);
    }
}
