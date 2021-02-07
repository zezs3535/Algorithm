#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)q.push(i);
	long long step = 1;
	long long cnt = 0;
	while (q.size() != 1) {
		long long key = ((step * step * step)-1) % q.size();
		if (key == cnt) {
			q.pop();
			cnt = 0;
			step++;
			continue;
		}
		for (long long i = 0; i < key; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
			cnt++;
		}
	}
	cout << q.front();
	return 0;
}