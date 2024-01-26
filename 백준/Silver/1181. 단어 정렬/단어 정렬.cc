#include<bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, string>> words;
set<string> wordSet;
int main(){
    cin >> n;
    for(int i = 0 ; i < n; i ++){
        string s;
        cin >> s;
        wordSet.insert(s);
    }
    for(auto e : wordSet){
        words.push_back({e.length(), e});
    }
    
    sort(words.begin(), words.end());
    for(int i = 0 ; i < words.size();  i++){
        cout << words[i].second <<"\n";
    }
}