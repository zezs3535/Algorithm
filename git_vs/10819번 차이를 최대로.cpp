#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	do {
		int tmp = 0;
		for (int i = 0; i < arr.size() - 1; i++) {
			tmp += abs(arr[i] - arr[i + 1]);
		}
		if (ans < tmp)ans = tmp;
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ans;
	return 0;
}