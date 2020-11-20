#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	while (n) {
		int tmp = n % 3;
		if (tmp == 2) {
			cout << "NO";
			return 0;
		}
		n /= 3;
	}
	cout << "YES";
	return 0;
}