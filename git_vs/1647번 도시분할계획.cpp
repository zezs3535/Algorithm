#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pii> arr[100001]; //{거리, 노드}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int q, w, e; cin >> q >> w >> e;
		arr[q].push_back({ e,w });
		arr[w].push_back({ e,q });
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> v(n + 1, false);
	v[1] = true;
	for (pii e : arr[1]) {
		pq.push(e);
	}
	int dis = 0;
	int maxDis = 0;
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (v[cur.second])continue;
		v[cur.second] = true;
		dis += cur.first;
		maxDis = max(maxDis, cur.first);
		for (pii e : arr[cur.second])pq.push(e);
	}
	cout << dis - maxDis;
	return 0;
}
