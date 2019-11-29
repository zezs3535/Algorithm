#include <iostream>

using namespace std;

int a[1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,k;
	cin >> N;
	a[0] = 1;
	a[1] = 1;
	int cnt;
	if (N < 2) {
		cout << 1;
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		cnt = 1;
		a[i] = cnt;
		while (1) {
			for (k = 1; i >= 2 * k; k++) {
				if (a[i] - a[i - k] == a[i - k] - a[i - 2 * k])
					break;
			}
			if (2 * k > i)
				break;
			cnt++;
			a[i] = cnt;
		}
	}
	cout << cnt;


	return 0;
}