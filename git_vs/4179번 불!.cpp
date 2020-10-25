#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int arr[1001][1001];
typedef pair<int, int> pii;
int n;
int m;
int answer = 0;
bool flag = false;
queue<pii> fire;
queue<pii> jihun;

void move() {
	int len = jihun.size();
	for(int i=0;i<len;i++){
		auto cur = jihun.front();
		jihun.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (cur.first == 0 || cur.first == n - 1 || cur.second == 0 || cur.second == m - 1) {
				flag = true;
				return;
			}
			if (ny >= n || ny < 0 || nx < 0 || nx >= m)continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = -3;
				jihun.push({ ny,nx });
			}
		}
	}
}

void fireMove() {
	int len = fire.size();
	for(int i=0;i<len;i++) {
		auto cur = fire.front();
		fire.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || ny < 0 || nx < 0 || nx >= m)continue;
			if (arr[ny][nx] == -1 || arr[ny][nx] == -2)continue;
			arr[ny][nx] = -2;
			fire.push({ ny,nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp; cin >> tmp;
			if (tmp == '#')arr[i][j] = -1; //º®Àº -1
			if (tmp == '.')arr[i][j] = 0;
			if (tmp == 'F') {
				arr[i][j] = -2;
				fire.push({ i,j });
			}
			if (tmp == 'J') {
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					cout << 1;
					return 0;
				}
				arr[i][j] = -3;
				jihun.push({ i,j });
			}
		}
	}
	while (true) {
		answer++;
		fireMove();
		move();
		if (flag) {
			cout << answer;
			return 0;
		}
		if (jihun.empty()) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
}