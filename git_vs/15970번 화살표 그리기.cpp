#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,spot,color;
	int ans = 0;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> spot >> color;
		v[color-1].push_back(spot);
	}
	for (int i = 0; i < n; i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0)
				ans += (v[i][j + 1] - v[i][j]);
			else if (j == v[i].size() - 1)
				ans += (v[i][j] - v[i][j - 1]);
			else {
				ans += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
			}
		}
	}
	cout << ans;
	return 0;
}