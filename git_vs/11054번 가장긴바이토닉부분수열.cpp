#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n; cin >> n;
	int ret = 0;
	vector<int> arr(n);
	vector<int> dp(n, 1);
	vector<int> rdp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j])rdp[i] = max(rdp[i], rdp[j] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i] + rdp[i]);
	}
	cout << ret - 1;
	return 0;
}