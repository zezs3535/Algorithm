#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;
typedef pair<int, int> pii;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<int> arr[1001];
int dis[1001] = { 0, };
int s, e;
void bfs(){
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == e) {
			cout << dis[cur];
			return;
		}
		for (int idx : arr[cur]) {
			if (dis[idx] != 0)continue;
			dis[idx] = dis[cur] + 1;
			q.push(idx);
		}
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> e;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int q, w; cin >> q >> w;
		arr[q].push_back(w);
		arr[w].push_back(q);
	}
	bfs();
	return 0;
}