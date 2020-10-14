#include <bits/stdc++.h>
#define W -1
#define L 1
using namespace std;

typedef pair<int, int> pii;
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(vector<vector<int>>& arr, int y, int x) {
	int cnt = 0;
	queue<pii> q;
	vector<vector<bool>> visit(r, vector<bool>(c, false));
	q.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		visit[cur.first][cur.second] = true;
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= r || nx >= c || ny < 0 || nx < 0 || arr[ny][nx] == -1 || visit[ny][nx]==true)continue;
			if (arr[ny][nx] != 1)continue;
			arr[ny][nx] = max(arr[ny][nx], arr[cur.first][cur.second] + 1);
			q.push({ ny,nx });
			visit[ny][nx] = true;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cnt = max(cnt, arr[i][j]);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	vector<vector<int>> arr(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'W')arr[i][j] = W;
			else {
				arr[i][j] = L;
			}
		}
	}
	int ret = 1;
	vector<vector<int>> copyarr(r, vector<int>(c, 0));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1) {
				copy(arr.begin(), arr.end(), copyarr.begin());
				ret = max(ret, bfs(copyarr, i, j));
			}
		}
	}
	cout << ret-1;
	return 0;
}