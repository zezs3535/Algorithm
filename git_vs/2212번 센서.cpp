#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	int ans = 0;
	vector<int> sensor(n);
	vector<int> dis;
	if (n <= k)cout << 0;
	else {
		for (int i = 0; i < n; i++) {
			cin >> sensor[i];
		}
		sort(sensor.begin(), sensor.end());
		for (int i = 0; i < n - 1; i++) {
			dis.push_back(sensor[i + 1] - sensor[i]);
		}
		sort(dis.begin(), dis.end());
		for (int i = 0; i < k - 1; i++) {
			dis.pop_back();
		}
		for (int i = 0; i < dis.size(); i++) {
			ans += dis[i];
		}
		cout << ans;
	}
	return 0;
}