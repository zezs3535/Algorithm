#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int answer = 0;
	do {
		bool flag = true;
		for (int i = 0; i < str.size()-1; i++) {
			if (str[i] == str[i + 1]) {
				flag = false;
				break;
			}
		}
		if (flag)answer++;
	} while (next_permutation(str.begin(), str.end()));
	cout << answer;
	return 0;
}