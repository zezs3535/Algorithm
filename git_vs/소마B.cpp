#include <iostream>
#include <vector>

using namespace std;

int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--) {
		bool flag = true;
		int n, m;
		cin >> n >> m;
		vector<vector<int> >map(n, vector<int>(m, 0));
		vector<vector<bool> >check(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (map[i][j] || check[i][j]) {
					int cnt = 0;
					for (int dir = 0; dir < 3; dir++) {
						int nx = j + dx[dir];
						int ny = i + dy[dir];
						if (map[ny][nx])cnt++;
						if (cnt == 3) {
							check[i][j] = true;
							check[i][j + 1] = true;
							check[i + 1][j] = true;
							check[i + 1][j + 1] = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					if (check[i][j])continue;
					else {
						flag = false;
					}
				}
			}
		}
		if (flag)cout << "YES\n";
		else {
			cout << "NO\n";
		}
	}
	return 0;
}