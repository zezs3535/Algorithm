#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll t = 1;
	ll cnt = 0;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		q.push_back(i + 1);
	}
	while (q.size() != 1) {
		ll key = ((t*t*t)-1) % q.size();
		if (cnt == key) {
			q.pop_front();
			t++;
			cnt = 0;
			continue;
		}
		for (ll i = 0; i < key; i++) {
			int tmp = q.front();
			q.pop_front();
			q.push_back(tmp);
			cnt++;
		}
	}
	cout << q[0];
	return 0;
}