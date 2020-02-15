#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}
	do {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}