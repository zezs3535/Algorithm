#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
char arr[51][51];
bool v[51][51];
bool ans = false;
void dfs(int y, int x, char key, int curDir) {
	v[y][x] = true;
	for (int idx = 0; idx < 4; idx++) {
		if (idx == ((curDir+2)%4))continue;
		int ny = y + dy[idx];
		int nx = x + dx[idx];
		if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx] != key)continue;
		if (v[ny][nx] && arr[ny][nx]==key) {
			//cout << arr[ny][nx] << " " << key << "\n";
			//cout << y << " " << x << " " << ny << " " << nx<<" "<<idx<<" "<<curDir<<"\n";
			ans = true;
			return;
		}
		dfs(ny, nx, key, idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!v[i][j]) {
				v[i][j] = true;
				dfs(i, j, arr[i][j], -5);
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}*/
	if (ans)cout << "Yes";
	else cout << "No";
	return 0;
}
