// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
string input;
int n, k;
int permu_num = 0;
bool isSelected[100];
string selected;

void dfs(){
    if(permu_num >= k) return;
    
    if(selected.length() == n){
        permu_num++;
        if(permu_num == k){
            cout << input << " " << k << " = " << selected << endl;
        }
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(isSelected[i]) continue;
        
        isSelected[i] = true;
        selected.push_back(input[i]);
        dfs();
        selected.pop_back();
        isSelected[i] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    while(cin >> input >> k){
        n = input.length();
        
        permu_num = 0;
        fill(isSelected, isSelected + n, false);
        selected.clear();
        
        dfs();
        
        if(permu_num < k) 
            cout << input << " " << k << " = " << "No permutation" << endl;        
    }

    return 0;
}
