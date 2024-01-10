#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[100000];
int result = 0x7fffffff;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int st,en;
    st = en = 0;
    sort(arr, arr + n);
    
    while(en < n && st < n){
        int diff = arr[en] - arr[st];
        if(m <= diff){
            result = min(result, diff);
            st++;
        }else {
            en++;
        }
    }
    cout << result;
}