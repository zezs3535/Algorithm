#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define endl "\n";
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int arr[1001][1001];
int row, col; //row = 가로, col = 세로
int ans = 1;

queue<pair<int, int>> q;

void bfs(pair<int, int> p) {
	int x = p.second; //5
	int y = p.first; //3
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= row || ny >= col || nx < 0 || ny < 0 || arr[ny][nx]==1 || arr[ny][nx]==-1)
			continue;
		else if(arr[ny][nx]==0){
			q.push(make_pair(ny, nx));
			arr[ny][nx] = arr[y][x] + 1;
			ans = max(arr[ny][nx], ans);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> row >> col;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first; //3
		int y = q.front().second; //5
		q.pop();
		bfs({ x,y });
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans-1;
	return 0;
}