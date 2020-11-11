#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char arr[12][6];
int canPop = 0;

void bfs(vector<vector<bool>>& visit, int y, int x) {
	int cnt = 0;
	char curColor = arr[y][x];
	queue<pii> q;
	queue<pii> del;
	q.push({ y,x });
	del.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= 12 || nx >= 6 || nx < 0 || ny < 0)continue;
			if (arr[ny][nx] == '.' || arr[ny][nx]!=curColor || visit[ny][nx]==true)continue;
			q.push({ ny,nx });
			visit[ny][nx] = true;
			del.push({ ny,nx });
			cnt++;
		}
	}
	if (cnt >= 3) {
		canPop++;
		while (!del.empty()) {
			auto cur = del.front();
			arr[cur.first][cur.second] = '.';
			del.pop();
		}
	}
	else {
		while (!del.empty())del.pop();
	}
}

void update() {
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				int tmp = i;
				while (1) {
					if (tmp + 1 < 12 && arr[tmp + 1][j] == '.') {
						tmp++;
					}
					else {
						if (tmp != i) {
							arr[tmp][j] = arr[i][j];
							arr[i][j] = '.';
						}
						break;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int answer = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	while(1){
		vector<vector<bool>> visit(12, vector<bool>(6, false));
		canPop = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && visit[i][j] == false) {
					visit[i][j] = true;
					bfs(visit, i, j);
				}
			}
		}
		if (canPop == 0)break;
		update();
		answer++;
	}
	cout << answer;
	return 0;
}