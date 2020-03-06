#include <bits/stdc++.h>

using namespace std;

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int> >map(n, vector<int>(n, 0));
	vector<vector<long long int> >dp(n, vector<long long int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int dir = 0; dir < 2; dir++) {
				int nx = j + dx[dir] * map[i][j];
				int ny = i + dy[dir] * map[i][j];
				if (nx > n - 1 || nx<0 || ny>n - 1 || ny < 0)continue;
				if (i == n - 1 && j == n - 1)continue;
				dp[ny][nx] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}