#include <iostream>

using namespace std;

int dp[1001] = { 1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	if (N < 2) {
		cout << dp[N];
		return 0;
	}
	else {
		for (int i = 2; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2])%10007;
		}
	}
	cout << dp[N];

	return 0;
}