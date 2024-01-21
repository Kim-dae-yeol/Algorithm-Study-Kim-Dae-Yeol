#include<iostream>
#include<queue>
int n;
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, less<int>> tmp_pq;
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    while(n--){
        int num;
        cin >> num;
        if(pq.empty() || pq.top() <= num){
            pq.push(num);
        }else if(pq.top() > num){
            tmp_pq.push(num);
        }
        
        int idx = cnt / 2 ;
        while(idx < tmp_pq.size()){
            auto val = tmp_pq.top(); tmp_pq.pop();
            pq.push(val);
        }
        
        while(idx > tmp_pq.size()){
            auto val = pq.top(); pq.pop();
            tmp_pq.push(val);
        }
        cnt++;
        cout << pq.top() << "\n";
    }
}