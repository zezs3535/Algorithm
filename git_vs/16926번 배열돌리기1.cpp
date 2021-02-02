#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, r;

void rotate(vector<vector<int>>& arr, int start) {
	for (int i = 0; i < start; i++) {
		int nextValue = arr[i][i];
		int y = i;
		int x = i;
		arr[i][i] = 0;
		int dir = 0;
		int tmp = 0;
		while (1) {
			if (dir == 0 && y == n - 1 - i && x == i) {
				dir = 1;
			}
			else if (dir == 1 && y == n - 1 - i && x == m - 1 - i) {
				dir = 2;
			}
			else if (dir == 2 && y == i&& x == m - 1 - i) {
				dir = 3;
			}
			else if (dir == 3 && y == i && x == i) {
				dir = 0;
			}
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = tmp;
				break;
			}
			tmp = arr[ny][nx];
			arr[ny][nx] = nextValue;
			nextValue = tmp;
			y = ny;
			x = nx;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < r; k++) {
		rotate(arr, min(n, m) / 2);
	}
	for (int i = 0; i < n; i++) {
		for(int j=0;j<m;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}