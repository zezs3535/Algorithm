#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int q, w; cin >> q >> w;
		arr[q][w] = 1;
		arr[w][q] = 1;
	}
	for (int k = 1; k <= n;k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (arr[i][k] != 0 && arr[k][j] != 0) {
					if (arr[i][j] == 0)arr[i][j] = arr[i][k] + arr[k][j];
					else
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}
	vector<int> comb(n + 1, 0);
	comb[0] = 1;
	fill(comb.end()-2, comb.end(), 1);
	int ans = 999999999;
	pii ansidx;
	do {
		pii tmpidx;
		int tmp = 0;
		int idxcnt = 0;
		for (int i = 1; i <= n; i++) {
			if (comb[i] && idxcnt == 0) {
				tmpidx.first = i;
				idxcnt++;
			}
			else if (comb[i] && idxcnt == 1)tmpidx.second = i;
		}
		for (int i = 1; i <= n; i++) {
			tmp += (min(arr[i][tmpidx.first], arr[i][tmpidx.second])*2);
		}
		if (ans > tmp) {
			ans = tmp;
			ansidx = tmpidx;
		}
		else if (ans == tmp) {
			if (ansidx.first == tmpidx.first)ansidx.second = min(ansidx.second, tmpidx.second);
			else if (ansidx.first > tmpidx.first)ansidx = tmpidx;
		}
	} while (next_permutation(comb.begin(), comb.end()));
	cout << ansidx.first << " " << ansidx.second << " " << ans;
	return 0;
}
