#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int visit[100001];
int sDFS[100001];

int dfs(int idx, int cnt, int start) {
	while (true) {
		if (visit[idx] != 0) {
			if (start != sDFS[idx]) {
				return 0;
			}
			return cnt - visit[idx];
		}
		visit[idx] = cnt;
		sDFS[idx] = start;
		idx = arr[idx];
		cnt += 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int ans = 0;
		memset(visit, 0, sizeof(visit));
		memset(sDFS, 0, sizeof(sDFS));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0)ans += dfs(i, 1, i);
		}
		cout << n - ans<<"\n";
	}
	return 0;
}