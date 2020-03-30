#include <bits/stdc++.h>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
using namespace std;

int bfscolor(vector<vector<char> >map,vector<vector<int> >visit, int n) { //rb¸¸
	queue<pair<int,int>> q;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) { q.push({ i,j }); visit[i][j] = 1; answer++; }
			char start = map[i][j];
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (nx >= 0 && ny >= 0 && nx < n&&ny < n&&visit[ny][nx]==0) {
						if (map[ny][nx] == start) {
							q.push({ ny,nx });
							visit[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
	return answer;
}
int bfs(vector<vector<char> >map, vector<vector<int> >visit, int n) { //rgb
	queue<pair<int, int>> q;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) { q.push({ i,j }); visit[i][j] = 1; answer++; }
			char start = map[i][j];
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (nx >= 0 && ny >= 0 && nx < n&&ny < n&&visit[ny][nx] == 0) {
						if (map[ny][nx] == start) {
							q.push({ ny,nx });
							visit[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<char> >maprgb(n, vector<char>(n, 0));
	vector<vector<char> >maprb(n, vector<char>(n, 0));
	vector<vector<int> >visit(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maprgb[i][j];
			maprb[i][j] = maprgb[i][j];
			if (maprgb[i][j] == 'G')maprb[i][j] = 'R';
		}
	}
	cout << bfs(maprgb, visit, n) << " " << bfscolor(maprb, visit, n);
	return 0;
}