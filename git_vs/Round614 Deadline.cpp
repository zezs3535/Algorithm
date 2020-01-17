#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n;
		int d;
		bool ans = false;
		cin >> n >> d;
		for (int i = 0; i*i <= d; i++) {
			if (i + ceil((double)d / (i + 1)) <= n) {
				ans = true;
			}
		}
		if (ans)cout << "YES\n";
		else {
			cout << "NO\n";
		}
	}
	return 0;
}