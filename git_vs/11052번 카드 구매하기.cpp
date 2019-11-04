#include <iostream>
#include <algorithm>
using namespace std;

int dp[10002] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int maxnum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
	if (N == 1) {
		cout << dp[N];
		return 0;
	}
	else {
		for (int i = 2; i <= N; i++) {
			for (int j = i; j>=(i-j); j--) {
				if (maxnum <= (dp[j] + dp[i - j]))
					maxnum = dp[j] + dp[i - j];
			}
			dp[i] = max(dp[i], maxnum);
		}
	}
	cout << dp[N];
	return 0;
}