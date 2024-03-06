#include <bits/stdc++.h>
using namespace std;
int h, m, t;
int main(){
    cin >> h >> m >> t;
    int addedHour = t / 60;
    int addedMin = t % 60;
    
    h += addedHour;
    m += addedMin;
    h += m / 60;
    h %= 24;
    m %= 60;
    cout << h << " " << m;
    return 0;
}