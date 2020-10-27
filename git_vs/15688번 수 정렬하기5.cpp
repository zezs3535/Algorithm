#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}