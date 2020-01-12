#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int dvisit[1001] = { 0, };
int bvisit[1001] = { 0, };
stack<int> s;
queue<int> q;
void dfs(const vector<vector<int> > &dp,int start) {
	if (dvisit[start])return;
	cout << start << " ";
	dvisit[start] = 1;
	for (int i = 0; i < dp[start].size(); i++) {
		s.push(dp[start][i]);
		while (!s.empty()) {
			int tmp = s.top();
			s.pop();
			dfs(dp, tmp);
		}
	}
}
void bfs(const vector<vector<int> > &dp,int start) {
	if (bvisit[start])return;
	cout << start << " ";
	bvisit[start] = 1;
	for (int i = 0; i < dp[start].size(); i++) {
		if(!bvisit[dp[start][i]])q.push(dp[start][i]);
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		bfs(dp, tmp);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int node, edge, start;
	cin >> node >> edge >> start;
	vector<vector<int> > dp(node+1);

	for (int i = 0; i < edge; i++) {
		int u, v;
		cin >> u >> v;
		dp[u].push_back(v);
		dp[v].push_back(u);
	}
	for (int i = 1; i <= node; i++) {
		sort(dp[i].begin(), dp[i].end());
	}
	dfs(dp,start);
	cout << "\n";
	bfs(dp,start);

	return 0;
}