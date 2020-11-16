//1. �ϳ��� ������ ������ �ּ� ���� Ʈ���� �߰��ϰ� �ش� ������ ����� ��� ������ ���� �߰��Ѵ�.
//
//2. ������ ����� ���� ���� ������ ������.
//
//3 - 1. ���� �ش� ������ �ּ� ���� Ʈ���� ���Ե� �� ������ �����Ѵٸ� �ƹ� �͵� ���� �ʰ� �Ѿ��.
//
//3 - 2. �ش� ������ �ּ� ���� Ʈ���� ���Ե� ���� u�� ���Ե��� ���� ���� v�� �����Ѵٸ� �켱 �ش� ������ ���� v�� �ּ� ���� Ʈ���� �߰��Ѵ�.�׸��� ���� v�� �ּ� ���� Ʈ���� ���Ե��� �ʴ� ������ �����ϴ� ��� ������ ���� �߰��Ѵ�.
//
//4. �ּ� ���� Ʈ���� V - 1���� ������ �߰��� �� ���� 2, 3�� ������ �ݺ��Ѵ�.
//��ó : https://blog.encrypted.gg/915?category=773649
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