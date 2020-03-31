#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int head = 0;
int n, m;
int answer = 0;
pii dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };	//입력은 북동남서, 방향회전은 북서남동!!!
vector<vector<int> >MAP(50, vector<int>(50, 0));
vector<vector<int> >visit(50, vector<int>(50, 0));
void search(int y, int x) {
	visit[y][x] = 1;
	answer++;
	int ny, nx;
	int a = 1;
	while (true) {
		int cantClean = 0;
		if (MAP[y][x] == 0 && visit[y][x] == 0) {
			visit[y][x] = 1;
			answer++;
		}
		for (int i = 0; i < 4; i++) {
			head+=3;
			ny = y + dir[head % 4].first;
			nx = x + dir[head % 4].second;
			if (MAP[ny][nx] == 0 && visit[ny][nx]==0) {
				y = ny;
				x = nx;
				break;
			}
			else if (MAP[ny][nx] == 1 || visit[ny][nx] == 1 || ny < 0 || nx < 0 || ny >= n || nx >= m) {
				cantClean++;
			}
		}
		if (cantClean == 4) {
			int tmp = head + 2;
			ny = y + dir[tmp % 4].first;
			nx = x + dir[tmp % 4].second;
			if (MAP[ny][nx] == 1)break;
			else {
				y = ny;
				x = nx;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	int x, y;
	cin >> y >> x >> head;
	pii pos = make_pair(y, x);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	search(pos.first, pos.second);
	cout << answer;
	return 0;
}