#include<iostream>

int input[5];
using namespace std;
int main(){
    for(int i = 0; i < 5; i++) cin >> input[i];
    
    int sum = 0;
    for(int i = 0; i< 5; i++){
        sum += input[i] * input[i];
    }
    sum %= 10;
    cout << sum;
    return 0;
}