#include<bits/stdc++.h>

using namespace std;

typedef struct abnode{
    long long number, dist;
}abnode;

int bfs(long long a, long long b){
    queue<abnode> num_q;
    abnode node;
    node.number = a;
    node.dist = 1;
    num_q.push(node);
    while(!num_q.empty()){
        abnode cur = num_q.front();
        num_q.pop();
        // cout << "cur number : " << cur.number << "\n";
        if(cur.number == b){return cur.dist;}
        
        
        if(cur.number * 2 <= b && cur.number * 2 > cur.number){
            abnode next;
            next.number = cur.number * 2;
            next.dist = cur.dist + 1;
            num_q.push(next);
        }
        
        if((cur.number * 10 + 1) <= b && (cur.number * 10 + 1) > cur.number){
            abnode next;
            next.number = cur.number * 10 + 1;
            next.dist = cur.dist + 1;
            num_q.push(next);
        }
    }
    
    return -1;
}
int main(){
    long long a, b;
    cin >> a >> b;
    cout << bfs(a, b);
}