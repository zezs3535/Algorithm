#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int > pii;
vector<pii> aircon;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n, m;

void goWind(vector<vector<int>>& arr, vector<vector<int>>& vis, int y, int x, int dir) {
	if (arr[y][x] == 9)return;
	vis[y][x] = 1; 
	if (arr[y][x] == 0 || arr[y][x] == 9) { //empty
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)return; //out of bounds
		goWind(arr, vis, ny, nx, dir);
	}
	else if (arr[y][x] == 1) {
		if (dir == 1 || dir == 3) { 
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)return; //out of bounds
			goWind(arr, vis, ny, nx, dir); 
		}
		//go
	}
	else if (arr[y][x] == 2) {
		if (dir == 2 || dir == 0) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)return; //out of bounds
			goWind(arr, vis, ny, nx, dir);
		}
	}
	else if (arr[y][x] == 3) {
		dir = 3 - dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)return; //out of bounds
		goWind(arr, vis, ny, nx, dir);
	}
	else if (arr[y][x] == 4) {
		if (dir % 2 == 0) {
			dir += 1;
		}
		else {
			dir -= 1;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)return; //out of bounds
		goWind(arr, vis, ny, nx, dir);
	}
}

void start(vector<vector<int>>& arr, vector<vector<int>>& vis, int y, int x) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)continue; //out of bounds
		goWind(arr, vis, ny, nx, dir);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				aircon.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < aircon.size(); i++) {
		vis[aircon[i].first][aircon[i].second] = 1;
		start(arr, vis, aircon[i].first, aircon[i].second);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j])ans++;
		}
	}
	cout << ans;
	return 0;
}