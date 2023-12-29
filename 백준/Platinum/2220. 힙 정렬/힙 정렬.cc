#include <iostream>
#include <vector>

using namespace std;

void swap_value(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> heap(n + 1, 0);
    heap[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = i - 1;
        heap[i] = i;
        swap_value(heap[i], heap[j]);

        while (j != 1) {
            swap_value(heap[j], heap[j / 2]);
            j /= 2;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << heap[i] << " ";
    }
	return 0;
}