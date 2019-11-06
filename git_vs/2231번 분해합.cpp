#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int num;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		num = i;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		if (i + sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
} 
