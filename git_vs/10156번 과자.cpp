#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int price, cnt, money;
	cin >> price >> cnt >> money;
	if (money < price*cnt)cout << price * cnt - money;
	else {
		cout << 0;
	}

	return 0;
}