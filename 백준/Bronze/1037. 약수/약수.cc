#include<bits/stdc++.h>

using namespace std;
int arr[51];

int main(){
    int n;
    cin >> n;
    int mx = -2100000000;
    int mn = 2100000000;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        if(arr[i] > mx) mx = arr[i];
        if(arr[i] < mn) mn = arr[i];
    }
    
    cout << mx * mn;
}