#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	if (next_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}