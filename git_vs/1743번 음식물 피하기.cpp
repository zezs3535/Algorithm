#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;

int bfs(vector<vector<int>>& arr, int y, int x) {
	int cnt = 0;
	queue<pii> q;
	q.push({ y,x });
	cnt++;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		arr[cur.first][cur.second] = 2; //탐색한 쓰레기는 2로 변경
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx]!=1)continue;
			q.push({ ny,nx });
			arr[ny][nx] = 2;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int maxTrash = 0;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		arr[r-1][c-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(arr[i][j]==1)maxTrash = max(maxTrash, bfs(arr,i, j));
		}
	}
	cout << maxTrash;
	return 0;
}