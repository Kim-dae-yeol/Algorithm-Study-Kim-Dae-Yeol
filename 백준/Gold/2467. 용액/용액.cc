#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> liquid;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        liquid.push_back(l);
    }
    
    int lo,hi;
    lo = 0; hi = n - 1;
    int min_value = INT_MAX;
    int left = lo;
    int right = hi;
    
    
    while(lo < hi){
        if(abs(min_value) >= abs(liquid[lo] + liquid[hi])){
            left = lo; right = hi;
            min_value = abs(liquid[lo] + liquid[hi]);
        }
        
        if(liquid[lo] + liquid[hi] < 0){
            lo ++;
        }else if(liquid[lo] + liquid[hi] > 0){
            hi--;
        }else {
            break;
        }
    }
    
    cout << liquid[left]<< " " << liquid[right] ;
}