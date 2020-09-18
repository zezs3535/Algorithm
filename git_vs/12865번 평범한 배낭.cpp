#include <bits/stdc++.h>

using namespace std;
int n, k;
int answer = -1;
pair<int, int> p[101];
int dp[101][100001] = { 0 };
bool cmp(pair<int,int> &a, pair<int,int> &b) {
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}

void search() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - p[i].first >= 0)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].first] + p[i].second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, cmp);
	search();
	cout << dp[n][k];
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}