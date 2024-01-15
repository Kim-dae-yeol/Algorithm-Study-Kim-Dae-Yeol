#include<cstdio>
#include<iostream>

std::pair<int, int> cache[41];
bool isCached[41];
void fibonacci(int n) {
    if (n == 0) {
        isCached[n] = true;
        cache[n] = {1, 0};
    } else if (n == 1) {
        isCached[n] = true;
        cache[n] = {0, 1};
    }else if(isCached[n]){
        return;
    } else {
        fibonacci(n - 1);
        fibonacci(n - 2);
        cache[n] = {cache[n-1].first + cache[n-2].first, cache[n-1].second + cache[n-2].second};
        isCached[n] = true;
    }
}

int main(){
    int t;
    int n;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        fibonacci(n);
        printf("%d %d\n" , cache[n].first, cache[n].second);
    }
}