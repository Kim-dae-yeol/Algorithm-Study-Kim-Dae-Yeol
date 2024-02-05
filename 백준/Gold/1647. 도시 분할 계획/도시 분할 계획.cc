
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;
int n, m;
priority_queue<pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> edges; // dist , (f, t)
int par[100001];

int find(int r){
    if(par[r] == r) return r;
    return par[r] = find(par[r]); //경로 찾기 압축 과정
}

bool union_if_not_same_group(int r, int v){
    r = find(r); v = find(v);
    if(r == v) return true;
    
    if(r < v) par[v] = r;
    else par[r] = v;
    return false;
}

int main()
{
    // 최소 신장 트리를 만든다 -> 가장 비싼 간선 하나를 지운다. 끝 
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,dist;
        cin >> a >> b >> dist;
        edges.push({dist, {a, b}});
    }
    
    for(int i = 1; i <= n ; i++){
        par[i] = i;
    }
    
    int cnt = 0;
    int lastDist = 0;
    int result = 0;
    while(edges.empty() == false){
        if(cnt == n - 1) break;
        auto cur = edges.top(); edges.pop();
        auto path = cur.second;
        
        if(union_if_not_same_group(path.first, path.second) == false){
            cnt++;
            // cout << "Add " << cur.first << "::" << path.first << " - "<<path.second <<"\n";
            lastDist = cur.first;
            result += cur.first;
        }
    }
    cout << result - lastDist;
    return 0;
}
