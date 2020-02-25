#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>> dp(46);
	dp[1].first = 0;
	dp[1].second = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i].first = dp[i - 1].second;
		dp[i].second = dp[i - 1].first + dp[i - 1].second;
	}
	cout << dp[n].first << " " << dp[n].second;
	return 0;
}