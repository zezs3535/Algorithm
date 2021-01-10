#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define MAX 2000000000
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<pii> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = MAX;
	}
	arr[0].second = 0;
	for (int i = 0; i < n; i++) {
		int jump = arr[i].first;
		for (int j = i + 1; j < i+ 1 + jump; j++) {
			if (j >= n)break;
			arr[j].second = min(arr[i].second + 1, arr[j].second);
		}
	}
	if (arr[n - 1].second == MAX) {
		cout << "-1";
	}
	else {
		cout << arr[n - 1].second;
	}
	return 0;
}