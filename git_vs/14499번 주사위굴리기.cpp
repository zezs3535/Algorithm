#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii dicePos;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dice[6] = { 0,0,0,0,0,0 };
int ndice[6] = { 0,0,0,0,0,0 };
void moveEast() {
	ndice[0] = dice[0];
	ndice[2] = dice[3];
	ndice[3] = dice[5];
	ndice[5] = dice[1];
	ndice[4] = dice[4];
	ndice[1] = dice[2];
}
void moveWest() {
	ndice[0] = dice[0];
	ndice[2] = dice[1];
	ndice[3] = dice[2];
	ndice[5] = dice[3];
	ndice[4] = dice[4];
	ndice[1] = dice[5];
}
void moveNorth() {
	ndice[0] = dice[5];
	ndice[2] = dice[0];
	ndice[3] = dice[3];
	ndice[5] = dice[4];
	ndice[4] = dice[2];
	ndice[1] = dice[1];
}
void moveSouth() {
	ndice[0] = dice[2];
	ndice[2] = dice[4];
	ndice[3] = dice[3];
	ndice[5] = dice[0];
	ndice[4] = dice[5];
	ndice[1] = dice[1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	dicePos.first = y;
	dicePos.second = x;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int dir; cin >> dir;
		dir--;
		int ny = dicePos.first + dy[dir];
		int nx = dicePos.second + dx[dir];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)continue;

		switch (dir) {
		case 0:
			moveEast();
			break;
		case 1:
			moveWest();
			break;
		case 2:
			moveNorth();
			break;
		case 3:
			moveSouth();
			break;
		}
		dicePos.first += dy[dir];
		dicePos.second += dx[dir];
		/*cout << "dir : "<<dir << "\n";*/
		for (int i = 0; i < 6; i++) {
			dice[i] = ndice[i];
		}
		/*cout << "\n";*/
		if (arr[dicePos.first][dicePos.second] == 0) {
			arr[dicePos.first][dicePos.second] = dice[2];
		}
		else if (arr[dicePos.first][dicePos.second] != 0) {
			dice[2] = arr[dicePos.first][dicePos.second];
			arr[dicePos.first][dicePos.second] = 0;
		}
		/*for (int i = 0; i < 6; i++) {
			cout << dice[i];
		}
		cout << "\n";*/
		cout << dice[5] << "\n";
	}

	return 0;
}