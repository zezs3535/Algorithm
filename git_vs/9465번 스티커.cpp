#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100001] = { 0, };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> dp[i][j];
			}
		}
		dp[0][1] = max(dp[0][0], dp[1][0] + dp[0][1]);
		dp[1][1] = max(dp[1][0], dp[0][0] + dp[1][1]);
		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				dp[i][j] = max(dp[(i + 1) % 2][j - 1], dp[i][j - 2])+dp[i][j];
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << max(dp[0][n - 1], dp[1][n - 1])<<"\n";
	}

	return 0;
}