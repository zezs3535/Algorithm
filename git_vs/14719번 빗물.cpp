#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> arr(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	int sum = 0;
	int sHeight = 0;
	for (int i = 0; i < m; i++) {
		if (sHeight <= arr[i]) { //배열의 높이가 기준보다 높을때
			ans += sum;
			sHeight = arr[i];
			sum = 0;
		}
		else {
			sum += (sHeight - arr[i]);
		}
	}
	sum = 0;
	sHeight = 0;
	for (int i = m-1; i >= 0; i--) {
		if (sHeight < arr[i]) { //배열의 높이가 기준보다 높을때
			ans += sum;
			sHeight = arr[i];
			sum = 0;
		}
		else {
			sum += sHeight - arr[i];
		}
	}
	cout << ans;
	return 0;
}