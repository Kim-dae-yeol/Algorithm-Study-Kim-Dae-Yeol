#include<iostream>
#include<cmath>
int scores[301];
int table_scores[301];

void score_steps() {
    using namespace std;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }
    table_scores[0] = 0;
    table_scores[1] = scores[1];
    table_scores[2] = scores[1] + scores[2];
    for (int i = 3; i <= n; i++) {
        table_scores[i] = max(table_scores[i - 3] + scores[i - 1] + scores[i],
                              table_scores[i - 2] + scores[i]);
    }

    cout << table_scores[n];
}

int main(){
    score_steps();
}