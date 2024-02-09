// /////////////////////////////////////////////////////////////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;

int main(){
    int days, avail_day, full_days;
    
    int t = 1;
    while(true){
        cin >> avail_day >> full_days >> days;
        if(avail_day == 0 && full_days == 0 && days == 0) break;
        int times = days / full_days;
        
        int sum = avail_day * times;
        sum += (avail_day > days % full_days) ? days % full_days : avail_day;
        cout << "Case " << t++ <<": " << sum << "\n";
    }
}