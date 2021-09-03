#include <bits/stdc++.h>

using namespace std;

string getBinary(int num) {
	string ret = "0000";
	int idx = 3;
	while (num != 0) {
		if (num % 2 == 1)ret[idx] = '1';
		num /= 2;
		idx--;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int num; cin >> num;
		if (num >= 16) {
			int tmp = num - 16;
			int d = tmp / 14;
			int m = tmp % 14;
			if (d % 2 == 0) {
				num = 14 - m;
			}
			else {
				num = m+2;
			}
		}
		string ans = getBinary(num);
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '0')cout << 'V';
			else {
				cout << "µş±â";
			}
		}
		cout << "\n";
	}

	return 0;
}

/*
1 29 57 0001
2 28 30 56 0010
3 27 31 55 0011
4 26 32 54 0100
5 25 33 53 0101
6 24 34 52 0110
7 23 35 51 0111
8 22 36 50 1000
9 21 37 49 1001
10 20 38 48 1010
11 19 39 47 1011
12 18 40 46 1100
13 17 41 45 1101
14 16 42 44 1110
15 43 1111


*/