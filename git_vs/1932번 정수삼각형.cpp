#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501] = { 0, };
int ans[501][501] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int tmp;
			cin >> tmp;
			dp[i][j] = tmp;
		}
	}
	ans[0][0] = dp[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i!=0)
			{
				if (j == 0) {
					ans[i][j] = dp[i][j] + ans[i - 1][j];
				}
				if (j == i) {
					ans[i][j] = dp[i][j] + ans[i - 1][j - 1];
				}
				if (j != 0 && j != i) {
					ans[i][j] = dp[i][j] + (max(ans[i - 1][j - 1], ans[i - 1][j]));
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (answer <= ans[n - 1][i])answer = ans[n - 1][i];
	}
	cout << answer;
	return 0;
}