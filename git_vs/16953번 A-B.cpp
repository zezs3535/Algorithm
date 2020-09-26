#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int b, e;
	cin >> b >> e;
	int cnt = 0;
	while (e > b) {
		cnt++;
		if (e % 10 == 1) {
			e /= 10;
			continue;
		}
		else if (e % 2 == 0) {
			e /= 2;
			continue;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	if(b==e)cout << cnt+1;
	else {
		cout << -1;
	}
	return 0;
}