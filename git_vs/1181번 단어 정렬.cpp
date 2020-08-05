#include <bits/stdc++.h>

using namespace std;

bool cmp(string &a, string &b) {
	if (a.size() == b.size())return a < b;
	else {
		return a.size() < b.size();
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()),arr.end());
	for (auto it : arr)cout << it << "\n";

	return 0;
}