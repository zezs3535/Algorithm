#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int dz[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };

struct pos {
	int H;
	int Y;
	int X;
};

int arr[31][31][31];
int h, n, m;
queue<pos> q;
pos escape;

void bfs() {
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int idx = 0; idx < 6; idx++) {
			int nz = cur.H + dz[idx];
			int ny = cur.Y + dy[idx];
			int nx = cur.X + dx[idx];
			if (nz >= h || nz < 0 || ny >= n || ny < 0 || nx >= m || nx < 0)continue;
			if (arr[nz][ny][nx] == -1 || arr[nz][ny][nx]!=0)continue;
			q.push({ nz,ny,nx });
			arr[nz][ny][nx]=arr[cur.H][cur.Y][cur.X]+1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	while (true) {
		cin >> h >> n >> m;
		if (h == 0 && n == 0 && m == 0)break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					char tmp; cin >> tmp;
					if (tmp == 'S')q.push({ i, j, k });
					if (tmp == 'E') {
						escape.H = i;
						escape.Y = j;
						escape.X = k;
					}
					if (tmp == '#')arr[i][j][k] = -1;
					if (tmp == '.')arr[i][j][k] = 0;
				}
			}
		}
		bfs();
		if (arr[escape.H][escape.Y][escape.X] == 0) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << arr[escape.H][escape.Y][escape.X] << " minute(s).\n";
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					arr[i][j][k] = 0;
				}
			}
		}
	}
	return 0;
}