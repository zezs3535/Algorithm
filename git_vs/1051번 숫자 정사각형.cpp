#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int answer = 1;
	vector<vector<int> >map(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int key = map[i][j];
			int cnt = 0;
			while (i+cnt < n&&j+cnt < m) {
				cnt++;
				if (i + cnt == n || j + cnt == m)break;
				if (map[i][j + cnt] == key && map[i + cnt][j] == key) {
					if (map[i + cnt][j + cnt] == key)answer = max(answer, (cnt + 1)*(cnt + 1));
				}
			}
		}
	}
	cout << answer;
	return 0;
}