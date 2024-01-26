#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> result(100001);
bool has[2001];
int main(){
    cin >> n;
    result.resize(0);
    for(int i = 0 ; i < n; i++){
        int num;
        cin >> num;
        if(has[num + 1000])continue;
        
        has[num + 1000] = true;
        result.push_back(num);
    }
    
    sort(result.begin(), result.end());
    
    for(auto e : result)
        cout << e << " ";
}