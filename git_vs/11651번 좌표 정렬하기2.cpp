#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii& a, pii& b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
	return 0;
}