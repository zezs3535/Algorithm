#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	vector<string> ans(n + m);
	vector<string>::iterator it;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
	ans.resize(it - ans.begin());
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}