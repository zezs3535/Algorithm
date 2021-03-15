#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n, m;
int answer = 0;
void makeWhite(vector<vector<int>>& copyarr, int y, int x, int wallCnt) {
	if (wallCnt == 2) { //bfs순환
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << copyarr[i][j];
			}
			cout << "\n";
		}
		cout << "\n";*/
		int blackCntSum = 0;
		bool v[21][21] = { false, };
		queue<pii> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copyarr[i][j] == 2 && !v[i][j]) {
					bool flag = true;
					int blackCnt = 1;
					v[i][j] = true;
					q.push({ i,j });
					while (!q.empty()) {
						pii cur = q.front(); q.pop();
						for (int idx = 0; idx < 4; idx++) {
							int ny = cur.first + dy[idx];
							int nx = cur.second + dx[idx];
							if (ny >= n || ny < 0 || nx >= m || nx < 0 || copyarr[ny][nx] == 1 || v[ny][nx]) { //다음이 테두리, 흰돌, 방문했으면
								continue;
							}
							if (copyarr[ny][nx] == 0 || copyarr[ny][nx]==9) {
								flag = false;
								continue;
							}
							if (copyarr[ny][nx] == 2) {
								q.push({ ny,nx });
								blackCnt++;
								v[ny][nx] = true;
							}
						}
					}
					if (flag) {
						blackCntSum += blackCnt;
						//cout << blackCnt << " "<<i<<" "<<j<<"\n";
					}
				}
			}
		}
		answer = max(answer, blackCntSum);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyarr[i][j] == 0) {
				copyarr[i][j] = 1;
				makeWhite(copyarr, i, j, wallCnt+1);
				copyarr[i][j] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> copyarr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			copyarr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				copyarr[i][j] = 1;
				makeWhite(copyarr, i, j, 1);
				copyarr[i][j] = 9;
			}
		}
	}
	cout << answer;
	return 0;
}