
#include<bits/stdc++.h>
using namespace std;

int n, k;
string numStr;
stack<char> numStk;
stack<char> resultStk;

int main(){
    int cnt = 0;
    cin >> n >> k >> numStr;
    
    for(int i = 0; i < n; i++){
        if(numStk.empty() || numStk.top() >= numStr[i] || cnt >= k){
            numStk.push(numStr[i]);
        }else {
            while((numStk.empty() == false && numStr[i] > numStk.top() && cnt < k)){
                cnt++;
                numStk.pop();
            }
            numStk.push(numStr[i]);
        }
    }
    
    while(cnt < k){
        numStk.pop();
        cnt++;
    }
    
    while(numStk.empty() == false){
        resultStk.push(numStk.top());
        numStk.pop();
    }
    
    while(resultStk.empty() == false){
        cout << resultStk.top();
        resultStk.pop();
    }
}