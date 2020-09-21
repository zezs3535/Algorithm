#include <bits/stdc++.h>

using namespace std;
int n, c;

int checkWifi(vector<int>& arr, int dis) {
	int cnt = 1;
	int install = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[install] + dis) {
			cnt++;
			install = i;
		}
	}

	return cnt;
}

int binarySearch(vector<int>& arr) {
	int l = 1;
	int r = arr[arr.size() - 1] - arr[0];
	int ret = 0;
	bool flag = false;
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 0;
		cnt = checkWifi(arr, mid);
		if (cnt >= c) { //개수가 c보다 더 많을 때
			l = mid + 1;
		}
		else if (cnt < c) {
			r = mid - 1;
		}
		if (ret < mid && cnt >= c)ret = mid;
		flag = true;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	cout<<binarySearch(arr);
	
	return 0;
}