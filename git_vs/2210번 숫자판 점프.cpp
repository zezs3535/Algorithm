#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[5][5];
set<string> s;
void dfs(int y, int x, string key) {
	if (key.size() == 6) {
		s.insert(key);
		return;
	}
	for (int idx = 0; idx < 4; idx++) {
		int ny = y + dy[idx];
		int nx = x + dx[idx];
		if (ny >= 5 || nx >= 5 || ny < 0 || nx < 0)continue;
		dfs(ny, nx, key + to_string(arr[ny][nx]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j,to_string(arr[i][j]));
		}
	}
	cout << s.size();
	return 0;
}