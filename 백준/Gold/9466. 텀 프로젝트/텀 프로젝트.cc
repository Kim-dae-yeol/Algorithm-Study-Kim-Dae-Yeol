#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005]; 

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while(true){
        //순회 
        state[cur] = x;
        cur = arr[cur];
        if(state[cur] == x){
            //사이클을 순회하면서 모든 노드를 사이클로 만듬
            while(true){
                if(state[cur] == CYCLE_IN){
                    return;
                }
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
        }
        
        if(state[cur] == CYCLE_IN){ return; }
        if(state[cur] != NOT_VISITED && state[cur] != x){ return; }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        fill(state,state + n + 1, NOT_VISITED);
        for(int i = 1; i<= n; i++){
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt = 0;
        for(int i = 1; i<= n; i++){
            if(state[i] != CYCLE_IN ) cnt ++;
        }
        cout << cnt << "\n";
    }
}