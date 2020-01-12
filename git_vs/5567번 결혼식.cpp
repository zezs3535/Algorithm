#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dp[501][501] = { 0, };
int cnt[501] = { 0, };
int m, n;

void search(int row) {
	for (int i = 1; i <= m; i++) {
		if (dp[row][i])cnt[i] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> first;
	cin >> m >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if (u == 1) {
			first.push(v); cnt[v] = 1;
		}
		if (v == 1) {
			first.push(u); cnt[u] = 1;
		}
		dp[u][v] = 1;
		dp[v][u] = 1;
	}
	while (!first.empty()) {
		int tmp;
		tmp = first.front();
		first.pop();
		search(tmp);
	}
	for (int i = 2; i <= m; i++) {
		if (cnt[i])sum++;
	}
	cout << sum;
	return 0;
}