#include <bits/stdc++.h>
#define MAX 2147483647

using namespace std;
typedef pair<int, int> pii;
bool cmp(int& a, int& b) {
	return abs(a) < abs(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int minAns = MAX;
	pii ans = { 0,0 };
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n-1; i++) {
		if (abs(arr[i + 1] + arr[i]) < minAns) {
			ans.first = arr[i];
			ans.second = arr[i + 1];
			minAns = abs(arr[i + 1] + arr[i]);
		}
	}
	if (ans.first < ans.second) {
		cout << ans.first << " " << ans.second;
	}
	else {
		cout << ans.second << " " << ans.first;
	}
	return 0;
}