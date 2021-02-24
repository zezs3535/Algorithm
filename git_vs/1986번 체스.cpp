#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii knightMove[8] = { {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2} };
pii queenMove[8] = { {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1} };
int n, m;
queue<pii> queen;
queue<pii> knight;

void search(vector<vector<int>>& arr) {
	while (!queen.empty()) { //queen의 공격 범위 탐색
		pii cur = queen.front();
		for (int idx = 0; idx < 8; idx++) {
			int cnt = 1;
			while (1) {
				int ny = cur.first + queenMove[idx].first * cnt;
				int nx = cur.second + queenMove[idx].second * cnt;
				if (ny >= n || ny < 0 || nx >= m || nx < 0)break; //맵을 벗어나면
				if (arr[ny][nx] == 1)break; //빈칸이 아니면
				arr[ny][nx] = 2;
				cnt++;
			}
		}
		queen.pop();
	}

	while (!knight.empty()) { //knight의 공격 범위 탐색
		pii cur = knight.front();
		for (int idx = 0; idx < 8; idx++) {
			int ny = cur.first + knightMove[idx].first;
			int nx = cur.second + knightMove[idx].second;
			if (ny >= n || ny < 0 || nx >= m || nx < 0)continue;
			if (arr[ny][nx] != 0)continue;
			arr[ny][nx] = 1;
		}
		knight.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int answer = 0;
	vector<vector<int>> arr(n, vector<int>(m, 0)); //빈 칸은 0, 장애물(말)은 1

	int q; cin >> q; //queen 입력
	for (int i = 0; i < q; i++) {
		int y, x; cin >> y >> x;
		arr[y-1][x-1] = 1;
		queen.push({ y - 1,x - 1 });
	}

	int k; cin >> k; //knight 입력
	for (int i = 0; i < k; i++) {
		int y, x; cin >> y >> x;
		arr[y - 1][x - 1] = 1;
		knight.push({ y - 1,x - 1 });
	}

	int p; cin >> p; //pawn은 체스판에 체크만
	for (int i = 0; i < p; i++) {
		int y, x; cin >> y >> x;
		arr[y - 1][x - 1] = 1;
	}

	search(arr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j])answer++;
		}
	}
	cout << answer;
	return 0;
}