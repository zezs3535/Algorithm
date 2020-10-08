#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int answer = 1;

void dfs(vector<vector<char>>& arr, vector<int> save, int i, int j, int depth) {
	if (answer < depth)answer = depth;
	for (int idx = 0; idx < 4; idx++) {
		int ny = dy[idx] + i;
		int nx = dx[idx] + j;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (save[arr[ny][nx] - 65]==1)continue;
		save[arr[ny][nx] - 65]=1;
		dfs(arr, save, ny, nx, depth + 1);
		save[arr[ny][nx] - 65] = 0;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> save(26, 0);
	save[arr[0][0] - 65]++;
	dfs(arr, save, 0, 0, 1);
	cout << answer;
	return 0;
}