#include <bits/stdc++.h>
#define pii pair<int,int>
#define stone 999
#define water 998

using namespace std;
queue<pii> S;
queue<pii> w;
pii dest;
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool check(vector<vector<int>>& arr) { //빈칸이 있으면 트루
	if (S.empty() && w.empty())return false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1)return true;
		}
	}
	return false;
}

void waterflood(vector<vector<int>>& arr, queue<pii> pos) {
	while (!pos.empty()) {
		auto cur = pos.front();
		pos.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == stone || arr[ny][nx] == water || arr[ny][nx] == 0 || arr[ny][nx]!=-1)continue;
			if (ny == dest.first && nx == dest.second)continue;
			arr[ny][nx] = water;
			w.push({ ny,nx });
		}
	}
}

void move(vector<vector<int>>& arr, queue<pii> pos1) {
	while (!pos1.empty()) {
		auto cur = pos1.front();
		pos1.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == stone || arr[ny][nx] == water || arr[ny][nx]!=-1 || arr[ny][nx]==0)continue;
			arr[ny][nx] = arr[cur.first][cur.second]+1;
			S.push({ ny,nx });
		}
	}
}

void bfs(vector<vector<int>>& arr) { //물 먼저 퍼지고, 고슴도치 움직이고
	while (true) {
		if (!check(arr))break;
		queue<pii> tmp;
		while (!w.empty()) {
			pii tmppos = w.front();
			w.pop(); tmp.push(tmppos);
		}
		waterflood(arr, tmp);

		queue<pii> tmp2;
		while (!S.empty()) {
			pii tmppos = S.front();
			S.pop(); tmp2.push(tmppos);
		}
		move(arr, tmp2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m,-1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'D') {
				dest.first = i;
				dest.second = j;
				arr[i][j] = -1;
			}
			else if (tmp == 'S') {
				S.push({ i,j });
				arr[i][j] = 0;
			}
			else if (tmp == 'X') {
				arr[i][j] = stone;
			}
			else if (tmp == '*') {
				w.push({ i,j });
				arr[i][j] = water;
			}
		}
	}	
	bfs(arr);
	if (arr[dest.first][dest.second]==-1)cout << "KAKTUS";
	else {
		cout << arr[dest.first][dest.second];
	}
	return 0;
}