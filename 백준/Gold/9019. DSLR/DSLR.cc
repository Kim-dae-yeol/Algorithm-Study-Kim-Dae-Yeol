
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int dig[4];
int t,a,b;
int cmd[10000];
int path[10000];
bool vis[10000];

int D(int a){
    return (a * 2 ) % 10000;
}

int S(int a){
    return a? a - 1 : 9999;
}
void string_to_dig(string s){
    int sidx = s.size() - 1;
    //"1234" -> {1,2,3,4}
    for(int i = 3; i >= 0; i--){
        dig[i] = sidx < 0 ? 0 : s[sidx--] - '0';
    }
}

int dig_to_int(){
    int ret = 0;
    int m = 1000;
    for(int i = 0 ;i < 4; i ++){
        ret += dig[i] * m;
        m /= 10;
    }
    return ret;
}

void print_dig(){
    cout << "dig :: {";
    for(int i = 0; i < 4; i++){
        cout << " " << dig[i];
    }
    cout << " }\n";
}

int L(int a){
    string s = to_string(a);
    string_to_dig(s);
    int cop[4];
    for(int i = 0 ; i < 4; i++){
        int nxt = (i + 1) % 4;
        //swap
        cop[i] = dig[nxt];
    }
    for(int i = 0 ;i < 4;i ++){
        dig[i] = cop[i];
    }
    return dig_to_int();
}

int R(int a){
    string s = to_string(a);
    string_to_dig(s);
    int cop[4];
    for(int i = 0 ; i < 4; i++){
        int nxt = (i - 1 + 4) % 4;
        cop[i] = dig[nxt];
    }
    for(int i = 0 ;i < 4;i ++){
        dig[i] = cop[i];
    }
    return dig_to_int();
}

void bfs(){
    queue<int> q;
    q.push(a);
    path[a] = a;
    while(q.empty() == false){
        int cur = q.front(); q.pop();
        
        if(cur == b) {return;}
        //연산 : DSLR 4가지 
        for(char nxtCmd : {'D','S','L','R'}){
            int nxt = 0;
            switch(nxtCmd){
                case 'D' :
                nxt = D(cur);
                break;
                case 'S' :
                nxt = S(cur);
                break;
                case 'L' :
                nxt = L(cur);
                break;
                case 'R' :
                nxt = R(cur);
                break;        
            }
            if(vis[nxt]) continue;
            vis[nxt] = true;
            cmd[nxt] = nxtCmd;
            path[nxt] = cur;
            q.push(nxt);
        }
    }
    
}
int main()
{
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a >> b;
        fill(path, path + 10000,-1);
        fill(cmd, cmd + 10000,0);
        fill(vis, vis + 10000, false);
        bfs();
        int cur = b;
        stack<char> result;
        while(cur != a){
            result.push(cmd[cur]);
            cur = path[cur];
        }
        
        while(result.empty()==false){
            cout <<result.top();
            result.pop();
        }
        cout << "\n";
    }
    return 0;
    
}
