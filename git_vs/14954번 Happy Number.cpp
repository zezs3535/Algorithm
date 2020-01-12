#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int sum = 0;
	int tmp = 0;
	cin >> n;
	while (n != 4) {
		sum = 0;
		while (n > 0) {
			tmp = n;
			sum = sum + ((n % 10)*(n % 10));
			n /= 10;
		}
		n = sum;
		if (sum == 1) {
			cout << "HAPPY";
			return 0;
		}
	}
	cout << "UNHAPPY";
	return 0;
}

