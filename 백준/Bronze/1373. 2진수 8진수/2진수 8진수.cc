#include<iostream>
using namespace std;
char output[500000];
int main(){
    string s;
    cin >> s;
    int idx = s.length()-1;
    while(idx >= 0){
        int sum = 0;
        for(int i = idx; i >= 0 && i > idx - 3; i--){
            sum += (s[i] - '0') << (idx - i); 
        }
        output[idx / 3] = sum + '0';
        idx -= 3;
    }
    cout << output;
    return 0;
}