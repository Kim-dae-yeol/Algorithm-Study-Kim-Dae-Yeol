#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];
int cnt = 0;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int st = 0;
    int en = st + m - 1;
    int sum = 0;
    
    for(int i = st; i <= en; i++){
        sum += arr[i];
    }
    int result = sum;
    while(st < n && en < n){
        if(result < sum){
            result = sum;
        }
        en++;
        sum += arr[en];
        sum -= arr[st];
        st++;
    }
    cout << result;
}