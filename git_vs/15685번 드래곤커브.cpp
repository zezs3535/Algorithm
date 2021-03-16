#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> curve;
int n;
int arr[101][101] = { 0, };
void goCurve(int y, int x, int dir, int gen) {
	arr[y][x] = 1;
	for (int i = 1; i <= pow(2, gen); i++) {
		int ny = y + dy[(dir + curve[i]) % 4];
		int nx = x + dx[(dir + curve[i]) % 4];
		arr[ny][nx] = 1;
		y = ny;
		x = nx;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	curve.push_back(0);
	curve.push_back(0);//0세대까지 입력
	cin >> n;
	int answer = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = pow(2,i-1); j >=1 ; j--) {
			curve.push_back((curve[j] + 1) % 4);
		}
	}
	for (int i = 0; i < n; i++) {
		int x, y, dir, gen; cin >> x >> y >> dir >> gen;
		goCurve(y, x, dir, gen);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) {
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}