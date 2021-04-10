#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dp[1001][1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		int mincnt = MAX;
		for (int j = 1; j < i; j++) {
			if (i-j<j) {
				dp[i][j] = dp[j][j] + 2*j-i+1;
			}
			else dp[i][j] = dp[i - j][j] + 1;
			mincnt = min(mincnt, dp[i][j]);
		}
		dp[i][i] = mincnt + 1;
	}
	int ans = MAX;
	for (int i = 1; i <= n; i++) {
		if (dp[n][i] == 0 || dp[n][i]==MAX)continue;
		ans = min(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}
