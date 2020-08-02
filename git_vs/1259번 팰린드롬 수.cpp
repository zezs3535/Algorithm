#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	while (s != "0") {
		bool flag = true;
		int len = s.size();
		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[len - 1 - i]) {
				cout << "no\n";
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "yes\n";
		}
		cin >> s;
	}

	return 0;
}