#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<int, vector<int>, less<int>> mq;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == 0) {
			if (pq.empty() && mq.empty())cout << "0\n";
			else if (pq.empty() && !mq.empty()) {
				cout << mq.top() << "\n";
				mq.pop();
			}
			else if (!pq.empty() && mq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				if (pq.top() > abs(mq.top())) {
					cout << mq.top() << "\n";
					mq.pop();
				}
				else if (pq.top() < abs(mq.top())) {
					cout << pq.top() << "\n";
					pq.pop();
				}
				else {
					cout << mq.top() << "\n";
					mq.pop();
				}
			}
		}
		else {
			if (tmp > 0)pq.push(tmp);
			else {
				mq.push(tmp);
			}
		}
	}
	return 0;
}