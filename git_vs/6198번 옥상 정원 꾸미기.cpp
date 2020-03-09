#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int height = 0;
	stack<int> s;
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> height;
		while (!s.empty()) {
			if (s.top() <= height)s.pop();
			else break;
		}
		s.push(height);
		ans += s.size() - 1;
	}
	cout << ans;
	return 0;
}