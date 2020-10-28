#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct iii {
	long long case00 = 0;
	long long case01 = 0;
	long long case10 = 0;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<iii> dp(n+1);
	dp[1].case00 = 1;
	dp[1].case01 = 1;
	dp[1].case10 = 1;
	for (int i = 2; i <= n; i++) {
		dp[i].case00 = (dp[i - 1].case00 + dp[i - 1].case01 + dp[i - 1].case10)%9901;
		dp[i].case01 = (dp[i - 1].case00 + dp[i - 1].case10)%9901;
		dp[i].case10 = (dp[i - 1].case00 + dp[i - 1].case01)%9901;
	}
	cout << (dp[n].case00 + dp[n].case01 + dp[n].case10)%9901;
	return 0;
}