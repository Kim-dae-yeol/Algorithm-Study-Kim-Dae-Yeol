#include<bits/stdc++.h>
using namespace std;
int t;
int arr[1000000];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;
    
    while(t--){
        int n, k;
        int result = 0;
        
        cin >> n >> k;
        int minDiff = 0x7fffffff;
        
        for(int i = 0; i< n; i++){
            cin >> arr[i];
        }
        int st = 0;
        int en = n - 1;
        sort(arr, arr + n);
        
        while(st < en){
            int sum = (arr[st] + arr[en]);
            int diff = abs(sum - k);
            
            if(diff < minDiff){
                minDiff = diff;
                result = 1;
            }else if(diff == minDiff){
                result++;
            }
            
            if(sum >= k){
                en--;
            }else{
                st++;
            }
        }
        cout << result << "\n";
    }
}