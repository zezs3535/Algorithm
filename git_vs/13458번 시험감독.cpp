#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)cin >> arr[i];

	int b, c; cin >> b >> c;
	long long ret = n;

	for (int i = 0; i < n; i++) {
		if (arr[i] - b > 0) {
			if ((arr[i] - b) % c == 0)ret += ((arr[i] - b) / c);
			else {
				ret += ((arr[i] - b) / c);
				ret++;
			}
		}
	}
	cout << ret;
	return 0;
}