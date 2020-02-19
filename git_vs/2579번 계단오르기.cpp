#include <iostream>
#include <algorithm>
using namespace std;

int dp[301][2] = { 0, };
int stair[301] = { 0, };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	dp[1][0] = stair[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i];
		dp[i][1] = dp[i - 1][0] + stair[i];
	}
	cout << max(dp[n][0], dp[n][1]);
	return 0;
}