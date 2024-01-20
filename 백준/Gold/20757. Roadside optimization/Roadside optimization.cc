#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> root;

int find(int x) {
    if (root[x] != x)
        root[x] = find(root[x]);
    return root[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return false;

    if (x < y)
        root[y] = x;
    else
        root[x] = y;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt, x, y;
    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        cnt = 0;
        root.resize(n);

        for (int i = 0; i < n; i++) {
            root[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                if (x == 1 && unite(i, j))
                    cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}