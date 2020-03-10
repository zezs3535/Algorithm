#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<vector<int> >arr(501, vector<int>(501, 0));
vector<vector<int> >dp(501, vector<int>(501, -1));
int n, m;

int dfs(int y, int x) {
	if (dp[y][x] != -1)return dp[y][x];
	if (y == n && x == m)return 1;
	dp[y][x] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= m && ny <= n && nx >= 1 && ny >= 1 && arr[ny][nx] < arr[y][x])dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 1);

	return 0;
}