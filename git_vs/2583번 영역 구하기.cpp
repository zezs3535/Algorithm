#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int arr[101][101];
int n, m, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void arrFill(int y1, int x1, int y2, int x2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			arr[i][j] = 1;
		}
	}
}

int bfs(int i, int j) {
	queue<pii> q;
	q.push({ i,j });
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		cnt++;
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || nx >= m || ny < 0 || nx < 0)continue;
			if (arr[ny][nx] != 0)continue;
			q.push({ ny,nx });
			arr[ny][nx] = 2;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arrFill(y1, x1, y2, x2);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 2;
				ans.push_back(bfs(i, j));
				cnt++;
			}
		}
	}
	cout << cnt<<"\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}