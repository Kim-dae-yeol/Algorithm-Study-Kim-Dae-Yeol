
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int seq[1000001];


size_t lis(){
    vector<int> answer;
    answer.push_back(seq[0]);
    
    for(int i = 1; i < n; i++){
        if(answer.back() < seq[i]){
            answer.push_back(seq[i]);
        }else {
            int low = lower_bound(answer.begin(), answer.end(), seq[i]) - answer.begin();
            answer[low] = seq[i];
        }
    }
    
    return answer.size();
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> seq[i];
    cout << lis();
    return 0;
}
