
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;

int n;
int main()
{
    cin >> n;
    int idx = 1;
    int num = 666;
    string numString;
    
    while(true){
        if(idx == n) {
            cout << num;
            break;
        }
        num++;
        numString = to_string(num);
        int len = numString.length();
        for(int i = 0; i < len - 2; i++){
            if(numString[i] == '6' && numString[i+1] == '6' && numString[i+2] == '6'){
                idx++;
                break;
            }
        }
        
    }
}
