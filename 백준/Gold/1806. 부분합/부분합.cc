#include<bits/stdc++.h>
using namespace std;

int n, s;
int arr[100000];
const int INF = 0x7fffffff;
int result = INF;

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int st, en = 0;
    
    int sum = arr[0];
    while(st < n && en < n){
        if(sum >= s){
            result = min(result, en - st + 1);
            sum -= arr[st];
            st++;
        }else {
            en++;
            sum+= arr[en];
        }
    }
    
    cout << (result == INF ? 0 : result);
}