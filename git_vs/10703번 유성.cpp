#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int  n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { //ºó °ø°£ 0, À¯¼º 1, ¶¥Àº 9·Î Ç¥Çö
			char tmp; cin >> tmp;
			if (tmp == 'X')arr[i][j] = 1;
			else if (tmp == '#')arr[i][j] = 9;
		}
	}

	int minDis = 9999;
	for (int i = 0; i < m; i++) {
		int meteorIdx = -10000;
		int landIdx = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == 1)meteorIdx = j;
			if (meteorIdx!=-10000 && arr[j][i] == 9) {
				landIdx = j;
				break;
			}
		}
		minDis = min(minDis, landIdx - meteorIdx - 1);
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < m; j++) {
			int ny = i - minDis;
			if (ny < 0)break;
			if (arr[i][j] == 0) {
				if (arr[ny][j] == 1) {
					arr[i][j] = 1;
					arr[ny][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)cout << '.';
			else if (arr[i][j] == 1)cout << 'X';
			else if (arr[i][j] == 9)cout << '#';
		}
		cout << "\n";
	}
	return 0;
}