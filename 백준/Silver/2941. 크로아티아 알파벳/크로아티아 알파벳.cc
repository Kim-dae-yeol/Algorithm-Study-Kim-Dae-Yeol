
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
string croatians[]{"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int lenCroatian = 8;
string input;

bool isSame(const string& value, int start, int end){
    string other;
    int len = input.length();
    if(end > len){
        return false;
    }
    
    for(int i = start; i < end; i++){
        other.push_back(input[i]);
    }
    int result = value.compare(other);
    return result == 0;
}

int main()
{
    
    cin >> input;
    int i = 0;
    int len = 0;
    
    while(input[i]){
        int charLen = 1;
        for(int j = 0; j < lenCroatian; j++){
            string croatian = croatians[j];
            int len = croatian.length();
            if(isSame(croatian, i, i + len)){
                charLen = len;
                break;
            }
        }
        len ++;
        i += charLen;
    }
    cout << len;
    return 0;
}
