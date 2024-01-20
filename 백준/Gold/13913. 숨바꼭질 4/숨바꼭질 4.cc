
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<queue>
#include<tuple>

int n, k;
int dist[200001];
int result[200001];

using namespace std;

int main()
{
    cin >> n >> k;
    fill(result, result + 200001, -1);
    fill(dist, dist + 200001, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while(q.empty() == false){
        int cur = q.front(); q.pop();
        if(cur == k ) break;
        
        for(int nxt : {cur << 1, cur - 1, cur + 1}){
            if(nxt < 200001 && nxt >= 0 && dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                result[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    cout << dist[k] << "\n";
    vector<int> ret;
    ret.push_back(k);
    int cur = result[k];
    while(cur != -1){
        ret.insert(ret.begin(), cur);
        cur = result[cur];
    }
    for(int e : ret){
        cout << e << " ";
    }
    return 0;
}
