#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001] = { 0, };

void dfs(int n) {
	check[n] = 1;
	for (int i = 0; i < a[n].size(); i++) {
		if (check[a[n][i]] == false) {
			dfs(a[n][i]);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i); cnt++;
		}
	}
	cout << cnt;
	return 0;
}