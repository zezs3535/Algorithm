#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
vector<int> visit(100001, false);

void bfs(int start, int end) {
	q.push({ start,0 });
	visit[start] = true;
	while (!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		if (pos == end) {
			cout << cnt;
			break;
		}
		q.pop();
		if (pos*2 <= 100000 && !visit[pos * 2]) {
			q.push({ pos * 2,cnt });
			visit[pos * 2] = true;
		}
		if (pos - 1 >= 0 && !visit[pos - 1]) {
			q.push({ pos - 1,cnt + 1 });
			visit[pos - 1] = true;
		}
		if (pos + 1 <= 100000 && !visit[pos + 1]) {
			q.push({ pos + 1,cnt + 1 });
			visit[pos + 1] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	bfs(n, k);
	return 0;
}