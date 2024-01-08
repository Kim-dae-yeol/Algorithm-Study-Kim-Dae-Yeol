// Online IDE - Code Editor, Compiler, Interpreter
// 불
#include<bits/stdc++.h>

using namespace std;
int n;

vector<int> queenPos;

bool upperD[42];
bool lowerD[42];
bool ver[21];
bool hor[21];

bool isEnd = false;
bool dfs(int row, int cnt){
    if(cnt == n){
        isEnd = true;
        for(const auto& ele : queenPos){
            cout << ele << " ";
        }
        return true;
    }
    
    if(queenPos[row - 1]){
        return dfs(row + 1, cnt);
    }
    
    for(int col = 1; col <= n && !isEnd; col++){
        if(upperD[row + col - 1] || lowerD[row - col + n] || ver[col]) continue;
        
        queenPos[row - 1] = col;
        ver[col] = true;
        upperD[row + col - 1] = true;
        lowerD[row - col + n] = true;
            
        dfs(row + 1, cnt + 1);
        if(isEnd){return true;}
        
        queenPos[row - 1] = 0;
        ver[col] = false;
        upperD[row + col - 1] = false;
        lowerD[row - col + n] = false;
    }
    
    return isEnd;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    
    for(int row = 1; row <= n; row++){
        int col;
        cin >> col;
        queenPos.push_back(col);
        if(col){
            cnt ++;
            hor[row] = true;
            ver[col] = true;
            upperD[row + col - 1] = true;
            lowerD[row - col + n] = true;
        }
    }
    
    bool canPos = dfs(1, cnt);
    
    if(!canPos){
        cout << -1;
    }
}
