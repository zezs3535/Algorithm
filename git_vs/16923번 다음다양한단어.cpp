#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int alpha[26] = { 0, };
string s;
char arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'a'] = 1;
		arr[i] = s[i];
	}
	
	for (int i = 0; i < 26; i++) {
		cnt += alpha[i];
	}

	if (cnt < 26) {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == 0) {
				s += (char(i) + 'a');
				cout << s;
				return 0;
			}
		}
	}
	else {
		if (next_permutation(arr, arr+27)) {
			cout << arr;
		}
		else {
			cout << "-1";
		}
		return 0;
	}
}