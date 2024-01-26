#include<bits/stdc++.h>

//터무니 없는 거리로 이동하려는 경우 :: 휴리스틱으로 처리
//
using namespace std;
vector<int> arr;
vector<int> arr2;
int main(){
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >>m;
    arr2.resize(m);
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    sort(arr.begin(), arr.end());
    for(int i = 0; i < m; i++){
        bool found = false;
        for(int low = 0, high = n - 1; low <= high; ){
            int mid = (low + high) / 2;
            if(arr[mid] == arr2[i]) {
                cout << 1 << "\n";
                found = true;
                break;
            }else if(arr[mid] > arr2[i]){
                high = mid - 1;
            }else if(arr[mid] < arr2[i]){
                low = mid + 1;
            }
        }
        if(found == false){
            cout << 0 <<"\n";
        }
    }
}