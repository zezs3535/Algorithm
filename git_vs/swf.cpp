#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int a, b;
	int h, w;
	char *check = new char[N];
	pair<int, int> bill;
	pair<int, int>wallet;
	for (int i = 0; i < N; i++) {
		cin >> check[i] >> a >> b;
		if (check[i] == '+') {
			if (b >= a) {
				bill.first = max(bill.first,a);
				bill.second = max(bill.second,b);
			}
			else {
				bill.first = max(bill.first,b);
				bill.second = max(bill.second,a);
			}
		}
		else {
			if (a >= b) {
				h = b;
				w = a;
			}
			else {
				h = a;
				w = b;
			}
			if ((bill.first <= h) && (bill.second <= w))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}