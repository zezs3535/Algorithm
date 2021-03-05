#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n;
struct Pipe {
	int dir[4]; //1,2,3 순서로 3시/5시/6시
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int answer = 0;
	vector<vector<Pipe>> dp(n, vector<Pipe>(n)); //dp배열
	vector<vector<int>> arr(n, vector<int>(n, 0)); //지도
	dp[0][1].dir[1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //배열 순회
			if (dp[i][j].dir[1] != 0) { //파이프가 오른쪽으로 나있을때
				if (j + 1 < n && arr[i][j + 1] == 0)dp[i][j + 1].dir[1] += dp[i][j].dir[1]; //오른쪽으로 연결
				if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0)dp[i + 1][j + 1].dir[2] += dp[i][j].dir[1]; //오른쪽아래로 연결
			}
			if (dp[i][j].dir[2] != 0) { //파이프가 오른쪽아래로 나있을때
				if (j + 1 < n && arr[i][j + 1] == 0)dp[i][j + 1].dir[1] += dp[i][j].dir[2]; //오른쪽으로 연결
				if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0)dp[i + 1][j + 1].dir[2] += dp[i][j].dir[2]; //오른쪽아래로 연결
				if (i + 1 < n && arr[i + 1][j] == 0)dp[i + 1][j].dir[3] += dp[i][j].dir[2];
			}
			if (dp[i][j].dir[3] != 0) { //파이프가 아래로 났을때
				if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0)dp[i + 1][j + 1].dir[2] += dp[i][j].dir[3]; //오른쪽아래로 연결
				if (i + 1 < n && arr[i + 1][j] == 0)dp[i + 1][j].dir[3] += dp[i][j].dir[3];
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		answer += dp[n - 1][n - 1].dir[i];
	}
	cout << answer;
	return 0;
}