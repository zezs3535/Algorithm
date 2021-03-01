#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m, t;
int totalBrick = 0;
int answer = 99999999;

void shoot(int arr[15][12], int shootCnt, int shootIdx, int brickCnt) {
	vector<vector<bool>> v(n, vector<bool>(m, false));
	int tmp[15][12];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	if (shootCnt == t || brickCnt==totalBrick) {
		answer = min(answer, totalBrick - brickCnt);
		return;
	}
	queue<pii> q;
	pii cur = { 0,shootIdx }; //시작 위치
	int bCnt = 0;
	
	while (1) { //쭉 내려오면서 0이 아닌곳을 만나면?
		if (cur.first >= n) {
			return; //맵을 나가면 끝
		}
		if (tmp[cur.first][cur.second] != 0) { //0이 아니면
			q.push(cur);
			break;
		}
		cur.first++;
	}
	while (!q.empty()) { //터질곳 탐색
		cur = q.front();
		int len = tmp[cur.first][cur.second]; //몇칸 터질지
		tmp[cur.first][cur.second] = 0;
		bCnt++;
		q.pop();
		v[cur.first][cur.second] = true;
		for (int idx = 0; idx < 4; idx++) { //4방향
			for (int i = 1; i < len; i++) { //2부터 한칸씩
				int ny = cur.first + dy[idx] * i;
				int nx = cur.second + dx[idx] * i;
				if (ny >= n || ny < 0 || nx >= m || nx < 0)break;
				if (v[ny][nx])continue;
				if (tmp[ny][nx] == 0)continue;
				if (tmp[ny][nx] != 0) {
					q.push({ ny,nx });
					v[ny][nx] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)v[i][j] = false;
	queue<int> g; //중력 큐
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (tmp[i][j] != 0) {
				g.push(tmp[i][j]);
				tmp[i][j] = 0;
			}
		}
		int idx = n - 1;
		while (!g.empty()) {
			tmp[idx][j] = g.front();
			g.pop();
			idx--;
		}
	}
	for (int i = 0; i < m; i++) {
		shoot(tmp, shootCnt + 1, i, brickCnt+bCnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test; cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		totalBrick = 0;
		answer = 999999999;
		cin >> t >> m >> n;
		int arr[15][12];
		int tmp[15][12];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 0)totalBrick++;
			}
		}
		if (totalBrick == 0) {
			cout << "#" << tc << " " << 0 << "\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		for (int j = 0; j < m; j++)shoot(tmp, 0, j, 0);
		cout << "#" << tc << " " << answer << "\n";
	}
	return 0;
}