#include<iostream>
int table_used[11];

void make_number_using_123() {
    using namespace std;
    int t;
    cin >> t;
    table_used[0] = 1;
    table_used[1] = 1;
    table_used[2] = 1 + table_used[1];
    table_used[3] = 1 + table_used[2] + table_used[1];

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 4; j <= n; j++) {
            table_used[j] = table_used[j - 1] + table_used[j - 2] + table_used[j - 3];
        }
        cout << table_used[n] << "\n";
    }

}
int main(){
    make_number_using_123();
}