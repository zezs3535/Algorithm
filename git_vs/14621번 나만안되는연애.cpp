#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	int answer = 0;
	vector<int> univ;
	vector<pii> edge[1001];
	vector<bool> visited(n + 1,false);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	univ.push_back(0); //인덱스 1부터 쓰려고 그냥 하나 넣기
	for (int i = 0; i < n; i++) {
		char tmp; cin >> tmp;
		if (tmp == 'M')univ.push_back(0); //남자는 0
		else {
			univ.push_back(1); //여자는 1
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		if (univ[u] == univ[v])continue;
		edge[u].push_back({ w,v });
		edge[v].push_back({ w,u });
	}
	visited[1] = true;
	for (pii e : edge[1])pq.push(e);
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visited[cur.second])continue;
		visited[cur.second] = true;
		answer += cur.first;
		for (pii e : edge[cur.second]) {
			pq.push(e);
		}
	}
	bool isCon = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			isCon = false;
			break;
		}
	}
	if(isCon)cout << answer;
	else {
		cout << "-1";
	}
	return 0;
}