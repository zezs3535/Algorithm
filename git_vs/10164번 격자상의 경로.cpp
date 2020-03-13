#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, check;
	int checkx=0, checky=0;
	cin >> n >> m >> check;

	vector<vector<int> >map(n, vector<int>(m, 0));
	vector<vector<int> >ans(n, vector<int>(m, 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = (i * m) + j + 1;
			if (map[i][j] == check) {
				checky = i;
				checkx = j;
			}
		}
	}
	if (!check) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
		}
		cout << ans[n-1][m-1];
		return 0;
	}
	else {
		for (int i = 1; i <= checky; i++) {
			for (int j = 1; j <= checkx; j++) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
		}
		for (int i = checky+1; i < n; i++) {
			for (int j = checkx+1; j < m; j++) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
		}
		cout << ans[checky][checkx] * ans[n-1][m-1];
		return 0;
	}
}