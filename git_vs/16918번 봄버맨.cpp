#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c, n;

void bfs(vector<vector<int>>& arr) {
	queue<pii> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j]!=0) {
				q.push({ i,j });
			}
			if (arr[i][j] == 2)arr[i][j] = 1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)continue;
			arr[ny][nx] = 1;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0)arr[i][j] = 2;
		}
	}
}

void fillBomb(vector<vector<int>>& arr) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1)arr[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> r >> c >> n;
	vector<vector<int>> arr(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char tmp; cin >> tmp;
			if (tmp == '.')arr[i][j] = 0;
			else if (tmp == 'O')arr[i][j] = 1;
		}
	}

	for (int sec = 1; sec < n; sec++) {
		if (sec % 2 == 1) {
			bfs(arr);
		}
		else {
			fillBomb(arr);
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 0)cout << "O";
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	return 0;
}