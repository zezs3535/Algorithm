#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int t, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int cnt = 0;
		vector<int> arr(a);
		vector<int> brr(b);
		for (int i = 0; i < a; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < b; i++) {
			cin >> brr[i];
		}
		sort(arr.begin(), arr.end());
		sort(brr.begin(), brr.end());
		for (int i = 0; i < a; i++) {
			cnt+=lower_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();
		}
		cout << cnt << "\n";
	}
	return 0;
}
