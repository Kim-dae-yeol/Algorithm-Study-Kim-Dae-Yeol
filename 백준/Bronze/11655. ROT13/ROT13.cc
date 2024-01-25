
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;
void rot13(char& c, const char base){
    int num = c - base;
    num += 13;
    num %= 26;
    c = num + base;
}
int main()
{
    string s;
    getline(cin, s);
    int i = 0;
    while(s[i]){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            rot13(s[i], 'A');
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            rot13(s[i], 'a');
        }
        i++;
    }
    cout << s;
    return 0;
}
