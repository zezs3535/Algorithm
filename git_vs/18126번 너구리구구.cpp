#include <bits/stdc++.h>

using namespace std;
typedef pair<int, long long> pii;

vector<pii> arr[5001]; //dis , max
vector<bool> visited(5001, false);
long long ans = 0;
void dfs(int idx, long long dis) {
	visited[idx] = true;
	for (int i = 0; i < arr[idx].size(); i++) {
		if (visited[arr[idx][i].first])continue;
		arr[idx][i].second += dis;
		ans = max(ans, arr[idx][i].second);
		dfs(arr[idx][i].first, arr[idx][i].second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v, w; cin >> u >> v >> w;
		arr[u].push_back({ v,w });
		arr[v].push_back({ u,w });
	}
	visited[1] = true;
	dfs(1,0);
	cout << ans;
	return 0;
}