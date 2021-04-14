#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 }; //0우 1하 2좌 3상
int dy[4] = { 0,1,0,-1 };
int n, m, t;
int up; //공기청정기 윗칸
int down; //공기청정기 아랫칸
queue<pii> dust;

void spread(vector<vector<int>>& arr, vector<vector<int>>& arr2) { //arr배열에서 arr2로 확산시킴
	arr2[up][0] = -1;
	arr2[down][0] = -1;
	while (!dust.empty()) {
		auto cur = dust.front(); dust.pop();
		int cy = cur.first;
		int cx = cur.second;
		int cdust = arr[cy][cx];
		int spreadcnt = 0;
		for (int idx = 0; idx < 4; idx++) {
			int ny = cy + dy[idx];
			int nx = cx + dx[idx];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)continue;
			if (arr[ny][nx] == -1 || arr2[ny][nx] == -1) {
				arr2[ny][nx] = -1;
				continue;
			}
			arr2[ny][nx] += cdust / 5;
			spreadcnt++;
		}
		arr2[cy][cx] = arr[cy][cx] - (cdust / 5) * spreadcnt + arr2[cy][cx];
	}
}

void clean(vector<vector<int>>& arr, vector<vector<int>>& arr2) {
	int cy = up;
	for (int i = cy; i > 0; i--) {
		if (i == cy)arr2[i - 1][0] = 0;
		else {
			arr2[i][0] = arr2[i - 1][0];
		}
	}
	for (int j = 0; j < m-1; j++) {
		arr2[0][j] = arr2[0][j + 1];
	}
	for (int i = 0; i < cy ; i++) {
		arr2[i][m-1] = arr2[i + 1][m-1];
	}
	for (int j = m-1; j > 0; j--) {
		if (j == 1) {
			arr2[cy][j] = 0;
			break;
		}
		arr2[cy][j] = arr2[cy][j - 1];
	}
	cy = down;
	for (int i = cy; i < n-1; i++) {
		if (i == cy)arr2[i + 1][0] = 0;
		else {
			arr2[i][0] = arr2[i + 1][0];
		}
	}
	for (int j = 0; j < m - 1; j++) {
		arr2[n-1][j] = arr2[n-1][j + 1];
	}
	for (int i = n-1; i > cy; i--) {
		arr2[i][m-1] = arr2[i - 1][m-1];
	}
	for (int j = m - 1; j > 0; j--) {
		if (j == 1) {
			arr2[cy][j] = 0;
			break;
		}
		arr2[cy][j] = arr2[cy][j - 1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr2[i][j] > 0)dust.push({ i,j });
			arr[i][j] = arr2[i][j];
			arr2[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	int ans = 0;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> arr2(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0)dust.push({ i,j });
			if (arr[i][j] == -1 && arr[i - 1][j] == -1) { //공기청정기 위치
				up = i - 1;
				down = i;
			}
		}
	}

	for (int i = 0; i < t; i++) { //t초동안 수행
		spread(arr, arr2); //확산 시키고
		clean(arr, arr2); //바람 불고 그 다음 dust에 위치 저장할것
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0)ans += arr[i][j];
		}
	}
	cout << ans;
	return 0;
}
