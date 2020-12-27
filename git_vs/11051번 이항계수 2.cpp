#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dp[1001][1001] = { 0, };
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j % 2 == 0)dp[i][j] = 1;
			else {
				dp[i][j] = i;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}
	cout << dp[n][k];
	return 0;
}