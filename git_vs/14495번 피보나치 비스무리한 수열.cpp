#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	long long int fibo[117];
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 3];
	}
	cout << fibo[n - 1];
	return 0;
}