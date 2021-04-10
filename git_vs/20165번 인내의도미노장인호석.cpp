#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
int ans = 0;

void push(vector<vector<int>>& arr, vector<vector<int>>& copy, int y, int x, char cdir) {
	if (arr[y][x] == 0)return; //넘어져있으면 return
	queue<pii> q;

	int dir = 0;
	if (cdir == 'E')dir = 0;
	else if (cdir == 'W')dir = 1;
	else if (cdir == 'S')dir = 2;
	else dir = 3;
	
	q.push({ y,x });
	arr[y][x] = 0;
	ans++;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int len = copy[cur.first][cur.second];
		for (int i = 1; i < len ; i++) {
			int ny = cur.first + dy[dir] * i;
			int nx = cur.second + dx[dir] * i;
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx]==0)continue;
			q.push({ ny,nx });
			arr[ny][nx] = 0;
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> n >> m >> t;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> copy(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) { //게임판 입력
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			copy[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < t; i++) { //공격 턴
		int y, x; cin >> y >> x;
		char cdir; cin >> cdir;
		push(arr, copy, y-1, x-1, cdir); //밀기
		cin >> y >> x;
		arr[y - 1][x - 1] = copy[y - 1][x - 1]; //복원
	}
	
	cout << ans<<"\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)cout << "F ";
			else cout << "S ";
		}
		cout << "\n";
	}
	return 0;
}
