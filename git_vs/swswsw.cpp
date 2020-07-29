#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int n; cin >> n;
	vector<pair<int, int>>manager(n, { 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> manager[i].first >> manager[i].second;
	}
	int m; cin >> m;
	vector<pair<int, int>> worker(m, { 0,0 });
	for (int i = 0; i < m; i++) {
		int c; cin >> c;
		cin >> worker[i].first >> worker[i].second;
		int ret = 0;
		
		for (int j = 0; j < n; j++) {
			if (worker[i].first > manager[j].first) {
				if (worker[i].first < manager[j].second) {
					ret += manager[j].second - worker[i].first;
				}
			}
			if (worker[i].first < manager[j].first) {
				if (worker[i].second < manager[j].second) {
					ret += worker[i].second - manager[j].first;
				}
				else {
					ret += manager[j].second - manager[j].first;
				}
			}
			if (worker[i].second > manager[j].first) {
				if (worker[i].second < manager[j].second) {
					ret += worker[i].second - manager[j].first;
				}
			}
		}
		cout << "ret : "<<ret << "\n";
	}
	return 0;
}