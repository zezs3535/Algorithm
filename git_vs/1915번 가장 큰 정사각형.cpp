#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> >map(n, vector<int>(m, 0));
	vector<vector<int> >dp(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[j] - '0';
			dp[i][j] = map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				if (i == 0 || j == 0)dp[i][j] = map[i][j];
				else {
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				}
				if (ans < dp[i][j])ans = dp[i][j];
			}
		}
	}
	cout << ans*ans;
	return 0;
}