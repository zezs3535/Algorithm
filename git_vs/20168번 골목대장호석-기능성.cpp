#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;
int n, m, start, dest, money;
int ans = MAX;

void dfs(vector<vector<int>>& arr, vector<bool>& v, int idx, int cost, int maxNum) {
	if (idx == dest) { //µµÂø
		if (cost <= money) { //µ·ÀÌ µÇ¾î¾ß ÇÏ°í
			ans = min(ans, maxNum);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[idx][i] != 0 && v[i] == false) {
			v[i] = true;
			dfs(arr, v, i, cost+arr[idx][i], max(maxNum,arr[idx][i]));
			v[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> start >> dest >> money;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	vector<bool> v(n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		arr[u][v] = w;
		arr[v][u] = w;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[start][i] != 0 && v[i] == false) {
			v[i] = true;
			dfs(arr, v, i, arr[start][i], arr[start][i]);
			v[i] = false;
		}
	}
	if (ans == MAX)cout << "-1";
	else cout << ans;
	return 0;
}