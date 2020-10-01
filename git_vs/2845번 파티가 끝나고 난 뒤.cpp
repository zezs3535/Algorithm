#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b; cin >> a >> b;
	int num[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		int tmp; cin >> tmp;
		cout << a * b - tmp << " ";
	}

	return 0;
}