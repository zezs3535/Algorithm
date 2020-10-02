#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int w, h;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void bfs(vector<vector<int>>& arr, vector<vector<bool>>& visit, int y, int x) {
	queue<pii> q;
	q.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 8; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
			if (visit[ny][nx] || arr[ny][nx]==0)continue;
			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)return 0;
		vector<vector<int>> arr(h, vector<int>(w, 0));
		vector<vector<bool>> visit(h, vector<bool>(w, false));
		int ret = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					visit[i][j] = true;
					ret++;
					bfs(arr, visit, i, j);
				}
			}
		}
		cout << ret << "\n";
	}
}