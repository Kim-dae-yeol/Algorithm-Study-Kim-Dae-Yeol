
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<string>
using namespace std;
char stack[1001];
int top = -1;

void print_all_stack(){
    while(top >= 0){
        cout << stack[top];
        top--;
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        
        for(int i = 0 ;i < s.length(); i++){
            if(s[i] == ' ') {
                //pop all stack values
                print_all_stack();
                cout << ' ';
            }else {
                stack[++top] = s[i];
            }
        }
        
        print_all_stack();
        cout << "\n"; 
    }
    return 0;

}
