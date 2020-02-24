#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> grape(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 2] + grape[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n];
	return 0;
}