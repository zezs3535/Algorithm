#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int day, total; cin >> day >> total;
	int a[31] = { 0, 1,0 };
	int b[31] = { 0, 0,1 };
	for (int i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	int first = 1;
	int sec = 0;
	while (1) {
		if ((total - first * a[day]) % b[day] == 0) {
			sec = (total - first * a[day]) / b[day];
			break;
		}
		first++;
	}
	cout << first<<"\n"<<sec;
	return 0;
}