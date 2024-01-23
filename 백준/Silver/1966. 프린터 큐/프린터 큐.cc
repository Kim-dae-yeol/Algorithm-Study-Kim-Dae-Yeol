
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<deque>
#include<cmath>

using namespace std;
int t,n,m;

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> m;
        deque<pair<int, int>> q;
        
        for(int i = 0 ; i < n; i++){
            int prior;
            cin >> prior;
            q.push_back({i, prior});
        }
        int cnt = 0;
        while(q.empty() == false) {
            auto cur = q.front(); q.pop_front();
            int mp = 0;
            for(auto e : q){
                mp = max(mp, e.second);
            }
            
            if(cur.second < mp){
                //push
                q.push_back(cur);
                continue;
            }
            
            cnt++;
            if(cur.first == m){
                cout << cnt << "\n";
                break;
            }
        }
    }
    return 0;
}
