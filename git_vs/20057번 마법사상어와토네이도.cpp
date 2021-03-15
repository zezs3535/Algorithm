#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int n;
int len = 1;
int dir = 0;
int timer = 0;
int answer = 0;
pii tornado;

void blowDust(vector<vector<int>>& arr) {
	int ty = tornado.first;
	int tx = tornado.second;
	int curDir = dir;
	int curDir1 = (dir + 1) % 4;
	int curDir2 = (dir + 2) % 4;
	int curDir3 = (dir + 3) % 4;
	int curDust = arr[ty][tx];
	int dust1 = curDust * 0.01;
	int dust2 = curDust * 0.02;
	int dust5 = curDust * 0.05;
	int dust7 = curDust * 0.07;
	int dust10 = curDust * 0.1;
	int dy1 = dy[curDir1];
	int dy2 = dy[curDir2];
	int dy3 = dy[curDir3];
	int dx1 = dx[curDir1];
	int dx2 = dx[curDir2];
	int dx3 = dx[curDir3];
	arr[ty][tx] = 0; //먼지를 치우고

	curDust -= dust7;
	if (ty + dy1 >= n || ty + dy1 < 0 || tx + dx1 >= n || tx + dx1 < 0) { //날라가면, y왼쪽
		answer += dust7;
	}
	else {
		arr[ty + dy1][tx + dx1] += dust7;
	}

	curDust -= dust7;
	if (ty + dy3 >= n || ty + dy3 < 0 || tx + dx3 >= n || tx + dx3 < 0) { //날라가면, y오른쪽
		answer += dust7;
	}
	else {
		arr[ty + dy3][tx + dx3] += dust7;
	}

	curDust -= dust2;
	if (ty + dy1 * 2 >= n || ty + dy1 * 2 < 0 || tx + dx1 * 2 >= n || tx + dx1 * 2 < 0) { //날라가면, y왼쪽2칸
		answer += dust2;
	}
	else {
		arr[ty + dy1 * 2][tx + dx1 * 2] += dust2;
	}
	curDust -= dust2;
	if (ty + dy3 * 2 >= n || ty + dy3 * 2 < 0 || tx + dx3 * 2 >= n || tx + dx3 * 2 < 0) { //날라가면, y오른쪽2칸
		answer += dust2;
	}
	else {
		arr[ty + dy3 * 2][tx + dx3 * 2] += dust2;
	}
	curDust -= dust1;
	if (ty + dy1 + dy2 >= n || ty + dy1 + dy2 < 0 || tx + dx1 + dx2 >= n || tx + dx1 + dx2 < 0) { //나가면 y왼쪽아래
		answer += dust1;
	}
	else {
		arr[ty + dy1 + dy2][tx + dx1 + dx2] += dust1;
	}
	curDust -= dust1;
	if (ty + dy2 + dy3 >= n || ty + dy2 + dy3 < 0 || tx + dx2 + dx3 >= n || tx + dx2 + dx3 < 0) { //나가면 y오른쪽아래
		answer += dust1;
	}
	else {
		arr[ty + dy2 + dy3][tx + dx2 + dx3] += dust1;
	}
	curDust -= dust10;
	if (ty + dy[dir] + dy1 >= n || ty + dy[dir] + dy1 < 0 || tx + dx[dir] + dx1 >= n || tx + dx[dir] + dx1 < 0) { //y왼쪽 위
		answer += dust10;
	}
	else {
		arr[ty + dy[dir] + dy1][tx + dx[dir] + dx1] += dust10;
	}
	curDust -= dust10;
	if (ty + dy[dir] + dy3 >= n || ty + dy[dir] + dy3 < 0 || tx + dx[dir] + dx3 >= n || tx + dx[dir] + dx3 < 0) { //y오른쪽 위
		answer += dust10;
	}
	else {
		arr[ty + dy[dir] + dy3][tx + dx[dir] + dx3] += dust10;
	}
	curDust -= dust5;
	if (ty + dy[dir] * 2 >= n || ty + dy[dir] * 2 < 0 || tx + dx[dir] * 2 >= n || tx + dx[dir] * 2 < 0) { //y앞으로 두칸
		answer += dust5;
	}
	else {
		arr[ty + dy[dir] * 2][tx + dx[dir] * 2] += dust5;
	}
	if (ty + dy[dir] >= n || ty + dy[dir] < 0 || tx + dx[dir] >= n || tx + dx[dir] < 0) { //남은건 앞에
		answer += curDust;
	}
	else {
		arr[ty + dy[dir]][tx + dx[dir]] += curDust;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	tornado = { n / 2,n / 2 };
	dir = 0;
	timer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) { //0,0에 도달할때까지 돌려
		for (int move = 0; move < len; move++) {
			tornado.first += dy[dir];
			tornado.second += dx[dir];
			blowDust(arr);
			if (tornado.first == 0 && tornado.second == 0)break;
		}
		if (tornado.first == 0 && tornado.second == 0)break;
		dir++;
		timer++;
		if (timer % 2 == 0) {
			if (dir == 4)dir = 0;
			len++;
		}
	}
	cout << answer;
	return 0;
}