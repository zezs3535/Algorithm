#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		vector<int> ans;
		int n;
		cin >> n;
		int power = 1;
		while (n > 0) {
			if (n % 10 != 0) {
				ans.push_back((n % 10)*power);
			}
			n /= 10;
			power *= 10;
		}
		cout << ans.size()<<"\n";
		for (auto i : ans)cout << i<<" ";
		cout << "\n";
	}


	return 0;
}