#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> >arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int test;
	cin >> test;
	while (test--) {
		int i, j, x, y;
		int ans = 0;
		cin >> i >> j >> x >> y;
		for (int q = i - 1; q < x; q++) {
			for (int p = j - 1; p < y; p++) {
				ans += arr[q][p];
			}
		}
		cout << ans<<"\n";
	}
	return 0;
}