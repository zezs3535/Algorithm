#include <bits/stdc++.h>
#define M 1234567891
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	long long ret = 0;
	long long mul = 1;
	for (int i = 0; i < s.size(); i++) {
		ret = (ret + (s[i] - 'a' + 1) * mul) % M;
		mul = (mul * 31) % M;
	}
	cout << ret;

	return 0;
}