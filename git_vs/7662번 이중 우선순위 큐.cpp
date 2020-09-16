#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		multiset<int> q;
		int tc; cin >> tc;
		for (int j = 0; j < tc; j++) {
			char ins;
			int num;
			cin >> ins >> num;
			if (ins == 'I') {
				q.insert(num);
			}
			else if (ins == 'D') {
				if (!q.empty()) {
					if (num == -1) {
						q.erase(q.begin());
					}
					else if (num == 1) {
						auto it = q.end();
						it--;
						q.erase(it);
					}
				}
			}
		}
		if (q.empty())cout << "EMPTY\n";
		else {
			cout << *q.rbegin() << " " << *q.begin()<<"\n";
		}
	}

	return 0;
}