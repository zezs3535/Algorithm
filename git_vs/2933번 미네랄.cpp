#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
void print(vector<vector<int>>& arr) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(arr[i][j]==1)cout << 'x';
			else {
				cout << '.';
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

bool checkCluster(vector<vector<int>>& arr, int y, int x) {
	vector<vector<bool>> v(n+1, vector<bool>(m+1, false));
	queue<pii> q;
	q.push({ y,x });
	v[y][x] = true;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny > n || nx > m || nx < 1 || ny<1 || v[ny][nx] || arr[ny][nx]==0)continue; //경계값 체크
			if (arr[ny][nx]==1) { //바닥에 붙어있고 미네랄이 있으면
				if (ny == n)return false;
				q.push({ ny,nx });
				v[ny][nx] = true;
			}
		}
	}

	return true;
}

void moveDown(vector<vector<int>>& arr, int y, int x) {
	vector<vector<bool>> v(n+1, vector<bool>(m+1, false));
	vector<bool> checkCol(m + 1);
	queue<pii> q;
	q.push({ y,x });
	v[y][x] = true;
	checkCol[x] = true;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny > n || nx > m || nx < 1 || ny < 1 || v[ny][nx] || arr[ny][nx]==0)continue; //경계값 체크
			q.push({ ny,nx });
			v[ny][nx] = true;
			checkCol[nx] = true;
		}
	}
	int minDis = 999;
	for (int j = 1; j <= m; j++) {
		int cntDis = 0;
		if (checkCol[j]) { //Column값이 있으면
			int clusterY = 999;
			for (int i = 1; i <= n; i++) { //위에서부터 탐색
				if (v[i][j]) {
					clusterY = i;
					cntDis = 0;
				}
				if (clusterY != 999 && !v[i][j] && arr[i][j])break;
				if (clusterY != 999 && !v[i][j])cntDis++;
			}
		}
		//cout << cntDis << " ";
		if(cntDis!=0)minDis = min(minDis, cntDis);
	}
	//cout << "minDis : "<<minDis << "\n";
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j]) {
				if (i + minDis > n)continue;
				arr[i + minDis][j] = 1;
				arr[i][j] = 0;
			}
		}
	}
}

void throwStick(vector<vector<int>>& arr, int height, int direction) {
	int i;
	bool isBreak = false;
	if (direction == 0) {
		for (i = 1; i <= m; i++) {
			if (arr[height][i] != 0) {
				isBreak = true;
				break;
			}
		}
	}
	else {
		for (i = m; i >= 1; i--) {
			if (arr[height][i] != 0) {
				isBreak = true;
				break;
			}
		}
	}
	if (!isBreak)return;
	arr[height][i] = 0;
	for (int idx = 0; idx < 4; idx++) {
		int ny = height + dy[idx];
		int nx = i + dx[idx];
		if (ny > n || ny<1 || nx>m || nx < 0)continue;
		if (arr[ny][nx]==1) { //미네랄이 있을때
			if (checkCluster(arr, ny, nx)) { //바닥과 떨어진 클러스터면?
				//cout << height << "\n";
				//print(arr);
				moveDown(arr, ny, nx); //내려줌
				//print(arr);
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
	int c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'x')arr[i][j] = 1;
		}
	}
	//print(arr);
	cin >> c;
	for (int i = 0; i < c; i++) {
		int h; cin >> h;
		if(i%2==0)throwStick(arr, n-h+1, 0); //왼쪽에서 던지기
		else {
			throwStick(arr, n-h+1, 1); //오른쪽에서 던지기
		}
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j])cout << 'x';
			else {
				cout << '.';
			}
		}
		cout << "\n";
	}
	return 0;
}