#include<bits/stdc++.h>
using namespace std;


int n;
int par[100];
pair<float, float> positions[100];

priority_queue<
    pair<float, pair<int, int>>,
    vector<pair<float, pair<int, int>>>,
    greater<pair<float, pair<int, int>>>> distances;
    
int find(int r){
    if(par[r] == r) return r;
    return par[r] = find(par[r]);
}

bool is_same_group_else_union(int r, int v){
    r = find(r); v = find(v);
    
    if(r == v) return true;
    if(r > v) par[r] = v;
    else par[v] = r;
    return false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n ;i++){
        cin >> positions[i].first >> positions[i].second;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(i == j) continue;
            
            float a = positions[i].first - positions[j].first;
            float b = positions[i].second - positions[j].second;
            float c = a * a + b * b;
            distances.push({sqrt(c), {i, j}});
        }
    }
    
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
    
    int cnt = 0;
    float sum = 0;
    while(cnt < n - 1){
        auto cur = distances.top(); distances.pop();
        auto pos = cur.second;
        
        if(is_same_group_else_union(pos.first, pos.second) == false){
            sum += cur.first;
            cnt++;
        }
    }

    cout << fixed << setprecision(2) << sum << "\n";
}


