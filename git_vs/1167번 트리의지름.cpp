#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<pii> arr[100001];
int n;
pii ans;
pii ans2;
void bfs(int idx, int dis, vector<bool>& v) {
	if (ans.first < dis) {
		ans.first = dis;
		ans.second = idx;
	}
	for (pii cur : arr[idx]) {
		if (!v[cur.first]) {
			v[cur.first] = true;
			bfs(cur.first, dis + cur.second, v);
		}
	}
}
void bfs2(int idx, int dis, vector<bool>& v) {
	if (ans2.first < dis) {
		ans2.first = dis;
		ans2.second = idx;
	}
	for (pii cur : arr[idx]) {
		if (!v[cur.first]) {
			v[cur.first] = true;
			bfs2(cur.first, dis + cur.second, v);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int node; cin >> node;
		while (1) {
			int q; cin >> q;
			if (q == -1)break;
			int w; cin >> w;
			arr[node].push_back({ q,w });
			arr[q].push_back({ node,w });
		}
	}
	vector<bool> v(n + 1, false);
	ans = { 0,0 };
	ans2 = { 0,0 };
	v[1] = true;
	bfs(1, 0, v); //한번 구하고

	fill(v.begin(), v.end(), false);
	v[ans.second] = true;
	bfs2(ans.second, 0, v); //한번 더 구하고

	cout << ans2.first;
	return 0;
}