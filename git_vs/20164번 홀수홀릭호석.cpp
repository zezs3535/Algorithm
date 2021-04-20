#include <bits/stdc++.h>

using namespace std;
int ansMax = 0;
int ansMin = 2147483647;

void solve(string s, int oddcnt) {
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] - '0') % 2 == 1)oddcnt++;
	}
	if (s.size() == 1) {
		ansMax = max(ansMax, oddcnt);
		ansMin = min(ansMin, oddcnt);
		return;
	}
	else if (s.size() == 2) {
		int num = s[0] - '0' + s[1] - '0';
		solve(to_string(num), oddcnt);
	}
	else {
		int len = s.size();
		for (int i = len - 1; i >= 2; i--) {
			for (int j = i - 1; j >= 1; j--) {
				int numA = 0;
				int numB = 0;
				int numC = 0;
				int idx = 1;
				for (int k = len - 1; k >= i; k--) {
					numA += (s[k] - '0') * idx;
					idx *= 10;
				}
				idx = 1;
				for (int k = i-1; k >= j; k--) {
					numB += (s[k] - '0') * idx;
					idx *= 10;
				}
				idx = 1;
				for (int k = j - 1; k >= 0; k--) {
					numC += (s[k] - '0') * idx;
					idx *= 10;
				}
				solve(to_string(numA + numB + numC), oddcnt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	int oddcnt = 0;
	solve(s, oddcnt);
	cout << ansMin<<" "<<ansMax;
	return 0;
}