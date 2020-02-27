#include <iostream>
#include <vector>
using namespace std;

int dp[1001][10] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	dp[n][0] = 1;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]%10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	cout << ans%10007;
	return 0;
}