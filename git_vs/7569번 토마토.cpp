#include <bits/stdc++.h>

using namespace std;

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
struct tint {
	int z;
	int y;
	int x;
};
typedef pair<int, int> pii;
queue<tint> pos;

int n, m, h;
int tomato[101][101][101];

int day = 0;
void bfs() {
	while (!pos.empty()) {
		auto cur = pos.front();
		pos.pop();
		for (int idx = 0; idx < 6; idx++) {
			int ny = dy[idx] + cur.y;
			int nx = dx[idx] + cur.x;
			int nz = dz[idx] + cur.z;
			if (ny >= n || nx >= m || nz >= h || ny < 0 || nx < 0 || nz < 0)continue;
			if (tomato[nz][ny][nx] != 0)continue;
			tomato[nz][ny][nx] = tomato[cur.z][cur.y][cur.x] + 1;
			pos.push({ nz,ny,nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;
	for (int z = 0; z < h; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomato[z][i][j];
				if (tomato[z][i][j] == 1)pos.push({ z,i,j });
			}
		}
	}
	bfs();
	for (int z = 0; z < h; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tomato[z][i][j] == 0) {
					cout << -1; return 0;
				}
				else {
					day = max(day, tomato[z][i][j]-1);
				}
			}
		}
	}
	cout << day;
	return 0;
}