#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		cout<<upper_bound(arr.begin(), arr.end(), key)- lower_bound(arr.begin(), arr.end(), key)<<" ";
	}

	return 0;
}