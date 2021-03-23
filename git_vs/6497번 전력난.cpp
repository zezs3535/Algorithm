#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> edge[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0)break;
		int maxAns = 0;
		int minAns = 0;
		int inputIdx = 0;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		bool flag = true;
		vector<bool> visited(n, false);
		while (1) {
			int u, v, w; cin >> u >> v >> w;
			edge[u].push_back({ w,v });
			edge[v].push_back({ w,u });
			maxAns += w;
			inputIdx++;
			if (inputIdx == m)break;
		}
		visited[0] = true;
		for (pii e : edge[0])pq.push(e);
		while (!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			if (visited[cur.second])continue;
			visited[cur.second] = true;
			minAns += cur.first;
			for (pii e : edge[cur.second])pq.push(e);
		}
		cout << maxAns - minAns<<"\n";
		visited.clear();
		for (int i = 0; i < n; i++)edge[i].clear();
	}
	return 0;
}