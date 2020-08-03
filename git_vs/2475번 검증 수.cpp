#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		answer += tmp * tmp;
	}
	cout << answer % 10;
	return 0;
}