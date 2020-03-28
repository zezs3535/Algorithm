#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 2)cout << 1;
	else if (n == 3)cout << 7;
	else {
		if (n % 2 == 0) {
			int k = n / 2;
			for (int i = 0; i < k; i++) {
				cout << 1;
			}
		}
		else {
			cout << 7;
			int k = n / 2;
			for (int i = 0; i < k - 1; i++) {
				cout << 1;
			}
		}
	}

	return 0;
}