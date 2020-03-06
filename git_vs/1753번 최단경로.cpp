#include <bits/stdc++.h>
#define INF 1e9+1
#define pii pair<int,int>

using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int v, e, st;
	cin >> v >> e >> st;
	vector<int> dis(20001, INF);
	vector<pii> adj[20001];
	dis[st] = 0;
	pq.push({ 0, st });
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	while (!pq.empty()) {
		int distance = pq.top().first, node = pq.top().second;
		pq.pop();
		if (dis[node] != distance)continue;
		for (int i = 0; i < adj[node].size(); i++) {
			if (dis[node] + adj[node][i].first < dis[adj[node][i].second]) {
				dis[adj[node][i].second] = dis[node] + adj[node][i].first;
				pq.push({ dis[node] + adj[node][i].first,adj[node][i].second });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dis[i] == INF)cout << "INF\n";
		else {
			cout << dis[i] << "\n";
		}
	}
	return 0;
}