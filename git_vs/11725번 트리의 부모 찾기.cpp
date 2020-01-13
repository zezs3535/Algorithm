#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int visit[100001] = { 0, }; //0이 아니면 방문한적있음, 부모 노드번호
stack<int> s;
void dfs(const vector<vector<int> > &dp) {
	visit[1] = 1;
	for (int i = 0; i < dp[1].size(); i++) {
		if (dp[1][i]) {
			s.push(dp[1][i]);
			visit[dp[1][i]] = 1;
		}
	}
	while (!s.empty()) {
		int tmp = s.top();
		s.pop();
		for (int i = 0; i < dp[tmp].size(); i++) {
			if (visit[dp[tmp][i]]==0) {
				s.push(dp[tmp][i]);
				visit[dp[tmp][i]] = tmp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int> > dp(n + 1);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		dp[u].push_back(v);
		dp[v].push_back(u);
	}
	dfs(dp);
	for (int i = 2; i <= n; i++) {
		cout << visit[i] << "\n";
	}
	return 0;
}