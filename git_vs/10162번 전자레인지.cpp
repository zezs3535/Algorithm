#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	int a = 0;
	int b = 0;
	int c = 0;
	while (T) {
		if (T > 0 && T < 10) {
			cout << "-1";
			return 0;
		}
		if (T >= 300) {
			a = T / 300;
			T = T % 300;
		}
		if (T >= 60 && T<300) {
			b = T / 60;
			T = T % 60;
		}
		if (T >= 10 && T<60) {
			c = T / 10;
			T = T % 10;
		}
	}
	cout << a << " " << b << " " << c;
	return 0;
}