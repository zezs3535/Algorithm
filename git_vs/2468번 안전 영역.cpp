#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(vector<vector<int>>& arr, vector<vector<bool>>& visit, int height, int y, int x) {
	queue<pii> q;
	q.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || ny < 0 || nx < 0 || nx >= n)continue;
			if (arr[ny][nx] <= height || visit[ny][nx]==true)continue;
			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	int maxRain = 0;
	int minRain = 101;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			maxRain = max(tmp, maxRain);
			minRain = min(tmp, minRain);
			arr[i][j] = tmp;
		}
	}
	if (maxRain == minRain) {
		cout << 1;
		return 0;
	}
	for (int height = minRain; height <= maxRain; height++) {
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > height && visit[i][j] == false) {
					visit[i][j] = true;
					bfs(arr, visit, height, i, j);
					cnt++;
				}
			}
		}
		answer = max(cnt, answer);
	}
	cout << answer;
	return 0;
}