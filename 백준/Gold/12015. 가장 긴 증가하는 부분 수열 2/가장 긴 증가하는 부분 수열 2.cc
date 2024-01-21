
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<set>
using namespace std;

vector<int> ans;
vector<int> seq;
int n;
int lis(){
    ans.push_back(seq[0]);
    for(int i = 1; i < n; i++){
        if(seq[i] > ans.back()){
            ans.push_back(seq[i]);
        }else {
            int low = lower_bound(ans.begin(), ans.end(), seq[i]) - ans.begin();
            
            ans[low] = seq[i];
        }
    }
    return ans.size();
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        seq.push_back(num);
    }
    
    cout << lis();
}
