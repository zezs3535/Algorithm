#include <iostream>

using namespace std;

long long int dp[81] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 1;
	int n;
	int i = 0;
	cin >> n;
	for (i = 3; i <= n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[i - 2] * 2 + dp[i - 1] * 2;
	return 0;
}