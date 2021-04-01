#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int dp[10001] = { 0, };
	cin >> n >> m;
	for (int i = 0; i <= m; i++) {
		dp[i] = 1;
	}
	for (int i = m; i <= n; i++) {
		dp[i] = (dp[i - 1]%MOD + dp[i - m]%MOD)%MOD;
	}
	cout << dp[n];
	return 0;
}