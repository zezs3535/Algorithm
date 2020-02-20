#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][3] = { 0, };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> r(n);
	vector<int> g(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	dp[0][0] = r[0];
	dp[0][1] = g[0];
	dp[0][2] = b[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}
	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	return 0;
}