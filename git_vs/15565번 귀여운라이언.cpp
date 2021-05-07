#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> arr(n);
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1)pos.push_back(i);
	}
	int l = 0;
	int r = k-1;
	int ans = 1e+6;
	if (pos.size() < k) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= pos.size() - k; i++) {
		ans = min(ans, pos[r++] - pos[l++]+1);
	}
	cout << ans;
	return 0;
}