#include<iostream>
#include<stack>

using namespace std;
stack<pair<int, int>> stk;
int n;
int pop(){
    int ret = stk.top().second;
    stk.pop();
    return ret;
}
void oasis() {
    long long result = 0;
    
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        int cnt = 1;
        while(stk.empty() == false && stk.top().first <= h) {
            if(!stk.empty() && stk.top().first == h){
                int val = pop();
                result += val;
                // cout << "result +=" << val << endl;
                cnt = val + 1;
            }else {
                cnt = 1;
                int val = pop();
                result += val;
                // cout << "result +=" << val << endl;
            }
        }
        
        if(!stk.empty()) {
            result ++;
            // cout << people[i] << "::" << "resut ++ " << endl;
        }
        
        stk.push({h, cnt});
    }
    
    cout << result;
}

int main(){
    cin >> n;
    oasis();
}