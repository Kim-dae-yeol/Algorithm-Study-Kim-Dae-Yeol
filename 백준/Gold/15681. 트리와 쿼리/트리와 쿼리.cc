#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> adj[100001];
vector<int> children[100001];
int par[100001];
int queries[100001];
int table[100001];

void make_tree(int root){
    for(int child : adj[root]){
        if(par[child] == 0){
            par[child] = root;
            children[root].push_back(child);
            make_tree(child);
        }
    }
}

int dfs(int root){
    int ret = 1;
    for(int child : children[root]){
        if(table[child] != 0){
            ret += table[child];
        }
        else {
            ret += dfs(child);
        }
    }
    table[root] = ret;
    return ret;
}

int main(){

    int n,r,q;
    //Input 
    cin >> n >> r >> q;
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Queries
    for(int i = 0; i < q; i++){
        cin >> queries[i];
    }

    //Make tree
    par[r] = -1;
    make_tree(r);

    //Answer
    for(int i = 0; i < q; i++){
        cout << dfs(queries[i]) << "\n";
    }

    return 0;
}