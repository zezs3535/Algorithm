#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n; cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp);
	}
	while (pq.size() != 1) {
		int tmp1 = pq.top();
		pq.pop();
		int tmp2 = pq.top();
		pq.pop();
		answer += tmp1 + tmp2;
		pq.push(tmp1 + tmp2);
	}
	cout << answer;
	return 0;
}