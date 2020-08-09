#include <bits/stdc++.h>

using namespace std;
int white = 0;
int blue = 0;
int n;
bool check(vector<vector<int>>& arr, int n, int y, int x) {
	int bcnt = 0;
	int wcnt = 0;
	int idy = y;
	int idx = x;
	for (int i = y; i < n+idy; i++) {
		for (int j = x; j < n+idx; j++) {
			if (arr[i][j] == 1)bcnt++;
			else {
				wcnt++;
			}
			if (bcnt > 0 && wcnt > 0)return false;
		}
	}
	if (bcnt == (n * n)) {
		blue++;
		return true;
	}
	else if (wcnt == (n * n)) {
		white++;
		return true;
	}
}

void solve(vector<vector<int>>& arr, int n, int y, int x) {
	if (!check(arr, n, y, x)) {
		solve(arr, n/2, y, x);
		solve(arr, n/2, y+(n/2), x);
		solve(arr, n/2, y, x+(n/2));
		solve(arr, n/2, y+(n/2), x+(n/2));
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(arr, n, 0, 0);
	cout << white << "\n" << blue;
	return 0;
}