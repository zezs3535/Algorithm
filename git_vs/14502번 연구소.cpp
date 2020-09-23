#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int,int>> virus;
int bfs(vector<vector<int>> map) {
	int cnt = 0;
	queue<pair<int, int>> tmp;
	pair<int, int> cur;
	for (int i = 0; i < virus.size(); i++) {
		cur = virus.front();
		virus.pop();
		tmp.push(cur);
		virus.push(cur);
	}
	//tmp에는 바이러스의 값이 다 들어간 상태
	while (!tmp.empty()) {
		cur = tmp.front();
		tmp.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= n || nx >= m || ny < 0 || nx < 0 || map[ny][nx] != 0)continue;
			tmp.push({ ny,nx });
			map[ny][nx] = 2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)cnt++;
		}
	}
	//cout << cnt << "\n";
	return cnt;
}

void makeWall(vector<vector<int>>& map, int wallcnt) {
	if (wallcnt == 3) {
		answer=max(answer,bfs(map));
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					makeWall(map, wallcnt + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> copyarr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)virus.push({ i,j });
		}
	}
	copy(arr.begin(), arr.end(), copyarr.begin());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				copyarr[i][j] = 1;
				makeWall(copyarr, 1);
				copyarr[i][j] = 0;
			}
		}
	}
	cout << answer;
	return 0;
}