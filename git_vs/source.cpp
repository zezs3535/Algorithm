#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> num;
	int n, k;
	string s;
	long long ans=0;
	int arr[15];
	cin >> n >> k;
	int size = n - k;
	cin >> s;
	for (int i = 0; i < n; i++) {
		arr[i] = s[i] - '0';
	}
	for (int i = 0; i < size; i++) {
		num.push_back(1);
	}
	for (int i = 0; i < k; i++) {
		num.push_back(0);
	}
	sort(num.begin(), num.end());
	do {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] == 1) {
				sum = sum * 10 + arr[i];
				if (sum == 0)break;
			}
		}
		ans += sum;
	} while (next_permutation(num.begin(), num.end()));
	cout << ans;

	return 0;
}