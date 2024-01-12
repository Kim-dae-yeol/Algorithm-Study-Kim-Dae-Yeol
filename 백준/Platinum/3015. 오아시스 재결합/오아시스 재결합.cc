#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> stk;

int main(void){
    long long N, ans = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        int h, cnt = 1;
        cin >> h;
        while( !stk.empty() && stk.top().first <= h ){
            if( stk.top().first == h ){
                ans += stk.top().second;
                cnt = stk.top().second + 1;
                stk.pop();
            }else{
                ans += stk.top().second;
                cnt = 1;
                stk.pop();
            }
        }
        if( !stk.empty() ) ans += 1;

        stk.push({h, cnt});
    }
    cout << ans ;
    return 0;
}