#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pii pair<int, int>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int map[100][100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int h, w;
		cin >> h >> w;
		memset(map, 0, sizeof(map));
		//vector<vector<int> >map(h, vector<int>(w, -1)); // HxW배열 선언
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '#')map[i][j] = 1;
			}
		}
		int group = 0;
		queue<pii> q;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
					q.push({ i,j });
					group++;
				}
				while (!q.empty()) {
					pii cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (nx<0 || ny<0 || nx>w - 1 || ny>h - 1)continue;
						if (map[ny][nx] == -1 || map[ny][nx] == 0)continue;
						q.push({ ny,nx });
						map[ny][nx] = 0;
					}
				}
			}
		}
		cout << group<<"\n";
	}
	return 0;
}