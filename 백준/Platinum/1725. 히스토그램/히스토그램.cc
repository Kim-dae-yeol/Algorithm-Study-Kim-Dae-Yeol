#include<bits/stdc++.h>
using namespace std;

long long solve(int left ,int right, vector<long long>& heights){
    if(left == right){
        return heights[left];
    }

    int mid = (left + right )/ 2;
    long long rect = max(solve(left, mid, heights), solve(mid+1, right, heights));

    int lo = mid, hi = mid + 1;
    long long height = min(heights[lo], heights[hi]);
    rect = max(rect, height * 2);

    while(lo > left || hi < right){
        if(hi < right && (lo == left || heights[lo-1] < heights[hi +1])){
            ++hi;
            height = min(height, heights[hi]);
        }else {
            lo--;
            height = min(height, heights[lo]);
        }
        rect = max(rect, height * (hi - lo + 1));
    }
    return rect;
}

long long largestRectangleArea(vector<long long>& heights) {
    return solve(0, heights.size() - 1, heights);
}

int main(){
    int n;
    cin >> n; 
    vector<long long> hs;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        hs.push_back(num);
    }
        
    cout << largestRectangleArea(hs) << "\n";
}
    