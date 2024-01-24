
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>
using namespace std;
string s[51];
int main()
{
    int n;
    int len;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> s[i];
    }
    
    len = s[0].length();
    for(int i = 0 ; i < len; i++){
        bool same = true;
        char c = s[0][i];
        for(int j = 1 ; j <n && same; j++){
            same = c == s[j][i];
        }
        cout << (same ? c : '?');
    }
    return 0;

}
