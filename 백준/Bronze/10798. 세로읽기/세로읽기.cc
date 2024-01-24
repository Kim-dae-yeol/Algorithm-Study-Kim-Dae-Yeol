
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<cmath>
using namespace std;
string s[5];
int main()
{
    int maxLen = 0;
    for(int i =0;i < 5;i ++){
        cin >> s[i];
        maxLen = max((int)s[i].length(), maxLen);
        
    }
    for(int i = 0; i < maxLen; i++){
        for(int j = 0 ; j < 5;j++){
            if(s[j].length() <= i){
                continue;
            }
            cout << s[j][i];
        }
    }
    //Aa0aP f985z 1Eh z2W3 1gk 6x
    //Aa0aP Af985 Bz1Eh Cz2W3 D1gk D6x
    //Aa0aPAf985Bz1EhCz2W3DD
    return 0;

}
