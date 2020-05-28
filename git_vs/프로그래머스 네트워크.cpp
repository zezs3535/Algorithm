#include <bits/stdc++.h>

using namespace std;
queue<int> q;
vector<bool> visit(200, false);
int n;
int bfs(vector<vector<int>>& map, int y, int x) {
	q.push(x);
	visit[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		//cout << cur << endl;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[cur][i] == 1 && visit[i] == false) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = 3;
	vector<vector<int>>map;
	map.push_back({ 1,1,0 });
	map.push_back({ 1,1,0 });
	map.push_back({ 0,0,1 });
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[j] == false) {
				ans += bfs(map, i, j);
			}
		}
	}
	cout << ans;
	return 0;
}