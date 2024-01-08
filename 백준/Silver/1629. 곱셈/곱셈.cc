// 1629: 곱셈

#include <iostream>

using namespace std;

#define ll long long

int power(ll n, int coef, int mod) {
	ll answer = 1;

	while (coef > 0) {
		if (coef % 2) {
			answer *= n;
			answer %= mod;
		}

		n *= n;
		n %= mod;

		coef /= 2;
	}

	return answer;
}

int main(void) {
	int a, b, c; cin >> a >> b >> c;

	cout << power(a, b, c);

	return 0;
}