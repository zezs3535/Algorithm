#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, L;
	cin >> n >> m >> L;
	vector<int> arr;
	arr.push_back(0);
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	arr.push_back(L);
	int maxNum = 0;
	for (int i = 1; i <= n+1; i++) {
		if (maxNum < arr[i] - arr[i - 1])maxNum = arr[i] - arr[i - 1];
	}
	int l = 0;
	int r = maxNum;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;
		int cur = 0;
		for (int i = 0; i < n+1; i++) {
			cnt += (arr[i + 1] - arr[i]) / mid;
			if ((arr[i + 1] - arr[i]) % mid == 0)cnt--;
		}
		if (cnt > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}