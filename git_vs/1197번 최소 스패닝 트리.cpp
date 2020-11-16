//1. 하나의 정점을 선택해 최소 신장 트리에 추가하고 해당 정점과 연결된 모든 간선을 힙에 추가한다.
//
//2. 힙에서 비용이 가장 작은 간선을 꺼낸다.
//
//3 - 1. 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무 것도 하지 않고 넘어간다.
//
//3 - 2. 해당 간선이 최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한다면 우선 해당 간선과 정점 v를 최소 신장 트리에 추가한다.그리고 정점 v과 최소 신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 힙에 추가한다.
//
//4. 최소 신장 트리에 V - 1개의 간선이 추가될 때 까지 2, 3번 과정을 반복한다.
//출처 : https://blog.encrypted.gg/915?category=773649
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<pii> node[10003];
	bool check[10003] = { 0, };
	int ans = 0;
	int cnt = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		node[u].push_back({ w,v });
		node[v].push_back({ w,u });
	}

	check[1] = true;
	for (pii idx : node[1])pq.push({ idx.first,idx.second });
	while (1) {
		pii cur = pq.top(); pq.pop();
		if (check[cur.second])continue;
		check[cur.second] = true;
		ans += cur.first;
		cnt++;
		if (cnt == n - 1)break;
		for (pii nxt : node[cur.second])pq.push({ nxt.first,nxt.second });
	}
	cout << ans;
	return 0;
}