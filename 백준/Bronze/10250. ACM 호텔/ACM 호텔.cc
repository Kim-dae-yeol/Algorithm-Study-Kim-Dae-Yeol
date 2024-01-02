/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    vector<string> result;
    cin >> t;
    for(int i = 0; i < t; i++ ){
        int h, w, n;
        cin >> h >> w >> n;
        int cur_floor = n % h;
        if(cur_floor == 0) {cur_floor = h;}
        int cur_w = n / h + (n % h > 0 ? 1 : 0);
        stringstream ss;
        ss << cur_floor;
        if(cur_w < 10){
            ss << "0";
        }
        ss << cur_w << "\n";
        result.push_back(ss.str());
    }
    
    for(const auto &s : result){
        cout << s;
    }
    return 0;
}
