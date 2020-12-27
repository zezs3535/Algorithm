#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int ret = 1;
	vector<pii> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = 1;
	}
	
	for (int i = arr.size() - 1; i >= 0; i--) {
		for (int j = arr.size() - 1; j > i; j--) {
			if (arr[i].first > arr[j].first) {
				arr[i].second = max(arr[i].second, arr[j].second + 1);
				ret = max(ret, arr[i].second);
			}
		}
	}
	cout << ret;
	return 0;
}