#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[10][4] = { 0, };
int arr2[10][4] = { 0, };
int ans = 0;

void inputArr(int t, int y, int x){
	//arr에 입력
	if (t == 1) {
		arr[y][x] = 1;
	}
	else if (t == 2) {
		arr[y][x] = 1;
		arr[y][x+1] = 1;
	}
	else if (t == 3) {
		arr[y][x] = 1;
		arr[y+1][x] = 1;
	}
	//arr2에 회전해서 입력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr2[i][j] = arr[4-1-j][i];
		}
	}
}

void blockDown(int arr[10][4]) {
	//미네랄 문제처럼 블록 내리기
	vector<vector<bool>> v(10, vector<bool>(4, false));
	vector<bool> checkCol(4);
	queue<pii> q;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				q.push({ i,j });
				v[i][j] = true;
				checkCol[j] = true;
				break;
			}
		}
	}
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= 4 || ny < 0 || nx >= 4 || nx < 0 || v[ny][nx] || arr[ny][nx] == 0)continue;
			if (arr[ny][nx] == 1) {
				q.push({ ny,nx });
				v[ny][nx] = true;
				checkCol[nx] = true;
			}
		}
	}

	int minDis = 999;
	for (int j = 0; j < 4; j++) {
		int cntDis = 0;
		if (checkCol[j]) {
			int blockY = 999;
			for (int i = 0; i < 10; i++) {
				if (v[i][j]) {
					blockY = i;
					cntDis = 0;
				}
				if (blockY != 999 && !v[i][j]) {
					if (arr[i][j])break;
					cntDis++;
				}
			}
		}
		if (cntDis != 0)minDis = min(minDis, cntDis);
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (v[i][j]) {
				if (i + minDis >= 10)continue;
				arr[i + minDis][j] = 1;
				arr[i][j] = 0;
			}
		}
	}
	v.clear();
	checkCol.clear();
}

void rcCheck(int arr[10][4]) {
	//행,열 체크해서 꽉 찬 부분있는지
	//있으면 터트리고 터진만큼 내림
	for (int i = 6; i < 10; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1)cnt++;
		}
		if (cnt == 4) {
			for (int k = i; k >= 5; k--) {
				for (int j = 0; j < 4; j++) {
					arr[k][j] = arr[k - 1][j];
				}
			}
			ans++;
			for (int j = 0; j < 4; j++) {
				arr[5][j] = 0;
			}
		}
	}
}

void midCheck(int arr[10][4]) {
	//중간에 2줄 부분을 체크
	//줄 수를 체크해서 그만큼 블록을 내림
	int height = 0;
	for (int i = 4; i < 6; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1)cnt++;
		}
		if (cnt>0)height++;
	}
	for (int i = 9; i >= 6; i--) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = arr[i - height][j];
		}
	}
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int bCnt = 0;
	for (int i = 0; i < n; i++) {
		int t, x, y; cin >> t >> y >> x;
		inputArr(t, y, x);
		blockDown(arr);
		blockDown(arr2);
		rcCheck(arr);
		rcCheck(arr2);
		midCheck(arr);
		midCheck(arr2);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = 0;
				arr2[i][j] = 0;
			}
		}
	}
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1)bCnt++;
			if (arr2[i][j] == 1)bCnt++;
		}
	}
	cout << ans << "\n" << bCnt;
	return 0;
}
