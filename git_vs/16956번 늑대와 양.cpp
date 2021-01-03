#include <bits/stdc++.h>

using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m, 'D'));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp; cin >> tmp;
			if (tmp == '.')continue;
			else {
				arr[i][j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char now = arr[i][j];
			if (now == 'D')continue;
			for (int idx = 0; idx < 4; idx++) {
				int ny = dy[idx] + i;
				int nx = dx[idx] + j;
				if (ny >= n || nx >= m || ny < 0 || nx < 0)continue;
				if ((now=='S' && arr[ny][nx]=='W') || (now=='W' && arr[ny][nx]=='S')) {
					cout << 0;
					return 0;
				}
			}
		}
	}
	cout << 1 << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << " \n";
	}
	return 0;
}