#include <bits/stdc++.h>

using namespace std;

int n;

int binarySearch(vector<pair<string, int>> &arr, string key) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid].first>key)r = mid - 1;
		else if (arr[mid].first<key)l = mid + 1;
		else {
			return arr[mid].second;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int m; cin >> m;
	vector<pair<string, int>> arr(n);
	vector<string> name(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		name[i] = arr[i].first;
		arr[i].second = i+1;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++) {
		string tmp; cin >> tmp;
		int tmp2 = 0;
		if (tmp[0] >= '0' && tmp[0] <= '9') {
			tmp2 = atoi(tmp.c_str());
			cout << name[tmp2-1]<<"\n";
		}
		else {
			cout<<binarySearch(arr,tmp)<<"\n";
		}	
	}
	return 0;
}