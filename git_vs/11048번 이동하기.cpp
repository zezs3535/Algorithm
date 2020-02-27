#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j>=2) {
				dp[i][j] += dp[i][j - 1];
			}
			else if (j == 1 && i >= 2) {
				dp[i][j] += dp[i - 1][j];
			}
			else {
				dp[i][j] += max(dp[i - 1][j - 1], max((dp[i - 1][j]), dp[i][j - 1]));
			}
		}
	}
	cout << dp[n][m];
	return 0;
}