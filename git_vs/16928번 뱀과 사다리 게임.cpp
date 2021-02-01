#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321
typedef pair<int, int> pii;
int ladOrSnake[101] = { 0, };
bool visited[101] = { false, };
int n, m;
int answer = MAX;
queue<pii> q;

void bfs(int pos) {
	while (!q.empty()) {
		auto cur = q.front(); //cur.first = 현재 위치, cur.second = 현재 위치까지 오는데 걸린 횟수
		q.pop();
		if (cur.first == 100) {
			answer = min(answer, cur.second);
			return;
		}
		for (int i = 1; i <= 6; i++) {
			int nx = cur.first + i;
			int ncnt = cur.second + 1;
			if ( nx > 100)continue;
			if (ladOrSnake[nx]) {
				q.push({ ladOrSnake[nx],ncnt});
				visited[nx] = true;
				visited[ladOrSnake[nx]] = true;
			}
			if (!visited[nx]) { //방문하지 않았으면
				q.push({ nx, ncnt });
				visited[nx] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		int q, w;
		cin >> q >> w;
		ladOrSnake[q] = w;
	}
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		ladOrSnake[q] = w;
	}
	q.push({ 1,0 });
	bfs(1);
	cout << answer;
	return 0;
}