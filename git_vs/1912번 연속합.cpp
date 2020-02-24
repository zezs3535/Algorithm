#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	int max = 0;
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	for (int i = 0; i < n; i++) {
		sum += array[i];
		if (sum > max)max = sum;
		if (sum < 0)sum = 0;
	}
	cout << max;
	return 0;
}