#include<bits/stdc++.h>

using namespace std;

int par[51];
const int DELETED = -2;
vector<int> childrens[51];

int count_leaf(int n){
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(par[i] == DELETED){ continue; }
        
        if(childrens[i].size() == 0){
            ret++;
        }
    }
    return ret;
}

void delete_node(int n){
    for(const auto& child : childrens[n]){
        delete_node(child);
    }
    
    if(par[n] != -1){
        auto iter = childrens[par[n]].begin();
        
        while(iter != childrens[par[n]].end()){
            if(*iter == n){
                childrens[par[n]].erase(iter);
                break;
            }
            iter++;
        }
    }
    
    childrens[n].clear();
    par[n] = DELETED;
}

int main(){
    int n;
    int del;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> par[i];
        
        if(par[i] != -1){ 
            childrens[par[i]].push_back(i);
        }
    }
    
    cin >> del;
    delete_node(del);
    cout << count_leaf(n);
}