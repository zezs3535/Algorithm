#include <bits/stdc++.h>

using namespace std;
#define MAXNUM 10000000
int n, m;
int ret = MAXNUM;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[1001][1001][2];

struct INFO {
	int y;
	int x;
	int cnt;
	int isBreak;
};

void bfs(vector<vector<int>>& arr, int ypos, int xpos) {
	queue<INFO> q;
	q.push({ ypos,xpos,1,0 });
	visited[ypos][xpos][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		visited[cur.y][cur.x][cur.isBreak] = 1;
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.y + dy[idx];
			int nx = cur.x + dx[idx];
			if (ny >= n || nx >= m || ny < 0 || nx < 0)continue; //범위 넘거나 방문했으면 ㅌㅌ
			if (visited[ny][nx][cur.isBreak] == 1)continue;
			if (arr[ny][nx] == -9 && cur.isBreak == 1)continue; //벽인데 이미 한번 깼으면 ㅌㅌ
			if (arr[ny][nx] == -9 && cur.isBreak==0) { //벽인데 아직 안깼으면 하나 깬다
				q.push({ ny,nx,cur.cnt + 1,1 });
				visited[ny][nx][cur.isBreak] = 1;
				continue;
			}
			else {
				q.push({ ny,nx,cur.cnt + 1,cur.isBreak });
				visited[ny][nx][cur.isBreak] = 1;
			}
			if (ny == n-1 && nx == m-1) {
				ret = min(ret, cur.cnt + 1);
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
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
			if (arr[i][j] == 1)arr[i][j] = -9;
		}
	}
	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}
	bfs(arr, 0, 0);
	if (ret == MAXNUM)cout << -1;
	else {
		cout << ret;
	}
	return 0;
}