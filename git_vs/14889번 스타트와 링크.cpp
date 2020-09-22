#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int> > map(n, vector<int>(n, 0));
	vector<int> check(n, -1);
	fill(check.begin()+n/2, check.end(), 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 10000000;
	do {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (check[i] == check[j])ret += check[j] * (map[i][j] + map[j][i]);
			}
		}
		ans = min(ans, abs(ret));
	} while (next_permutation(check.begin(), check.end()));
	cout << ans;
	return 0;
}