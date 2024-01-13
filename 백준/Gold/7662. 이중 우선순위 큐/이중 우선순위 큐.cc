#include <bits/stdc++.h>
using namespace std;
const int MAX = 1;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    multiset<int> pq;
    
    for(int i = 0; i < k; i++){
        char cmd;
        cin >> cmd;
        if(cmd == 'D'){
            int num;
            cin >> num;
            if(pq.empty()) continue;
            
            if (num == MAX) pq.erase(prev(pq.end()));
            else pq.erase(pq.begin());
        }else {
            int num;
            cin >> num;
            pq.insert(num);
        }
    }
    if(pq.empty()) cout << "EMPTY\n";
    else cout << *prev(pq.end()) <<' ' <<*pq.begin() <<  "\n";
  }
}