#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;

bool isEmpty(vector<vector<int>>& arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0)return false;
		}
	}
	return true;
}

void melting(vector<vector<int>>& arr, vector<vector<int>>& calc) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] -= calc[i][j];
			if (arr[i][j] < 0)arr[i][j] = 0;
		}
	}
}

void bfs(int y, int x, vector<vector<int>>& arr, vector<vector<bool>>& visit) {
	queue<pii> q;
	q.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || nx >= m || ny < 0 || nx < 0)continue;
			if (visit[ny][nx] == true)continue;
			if (arr[ny][nx] != 0) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int year = 0;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> calc(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (!isEmpty(arr)) {
		year++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					calc[i][j] = 0;
					for (int idx = 0; idx < 4; idx++) {
						int ny = dy[idx] + i;
						int nx = dx[idx] + j;
						if (ny >= n || nx >= m || ny < 0 || nx < 0)continue;
						if (arr[ny][nx] == 0)calc[i][j]++;
					}
				}
			}
		}
		melting(arr, calc);
		vector<vector<bool>> visit(n, vector<bool>(m, false));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && visit[i][j]==false) {
					cnt++;
					visit[i][j] = true;
					bfs(i, j, arr, visit);
				}
			}
		}
		if (cnt >= 2) {
			cout << year;
			return 0;
		}
	}
	cout << 0;
	return 0;
}