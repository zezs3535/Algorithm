#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

vector<vector<int> >arr(500, vector<int>(500, 0));
vector<vector<int> >dp(500, vector<int>(500, 1));
int n;

int dfs(int y, int x) {
	if (dp[y][x] > 1)return dp[y][x];
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && nx >= 0 && ny <= n - 1 && nx <= n - 1 && arr[ny][nx] > arr[y][x])dp[y][x] = max(dfs(ny, nx)+1, dp[y][x]);
	}
	return dp[y][x];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans;
	return 0;
}