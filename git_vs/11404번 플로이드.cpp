#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
int n;
int m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> m;
	int graph[105][105];
	for (int i = 1; i <= n; i++)fill(graph[i], graph[i] + n + 1, INF);
	for (int i = 1; i <= m; i++) {
		int s, e, c; cin >> s >> e >> c;
		graph[s][e] = min(graph[s][e], c);
	}
	for (int i = 1; i <= n; i++)graph[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k)continue;
				if (graph[j][k] >= graph[j][i] + graph[i][k])graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)graph[i][j] = 0;
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}