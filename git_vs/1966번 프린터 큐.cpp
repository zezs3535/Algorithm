#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int maxnum = 0;

int getmax(deque<int> q) {
	maxnum = 0;
	for (auto i : q) {
		if (maxnum <= i)
			maxnum = i;
		else
			continue;
	}
	return maxnum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
		int N, M;
		int tmp = 0;
		int cnt = 0;
		deque<int> q;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			q.push_back(tmp);
		}
		maxnum = getmax(q);
		while (true) {
			if (q[0] < maxnum) {
				tmp = q[0];
				q.pop_front();
				q.push_back(tmp);
				if (M == 0)
					M = N - 1;
				else
					M--;
				maxnum = getmax(q);
			}
			else if (q[0] == maxnum) {
				q.pop_front();
				cnt++;
				N--;
				if (M == 0)
					break;
				else {
					M--;
				}
				maxnum = getmax(q);
			}
		}
		cout << cnt<<"\n";
	}
	return 0;
}