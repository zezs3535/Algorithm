#include <bits/stdc++.h>

using namespace std;

int f(int n) {
	for (int i = 2; i <= n; i++) {
		if (n%i == 0)return i;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n, k;
		cin >> n >> k;
		if (n % 2 == 0)cout << n + 2 * k << "\n";
		else {
			cout << n + f(n) + 2 * (k - 1) << "\n";
		}
	}
	return 0;
}