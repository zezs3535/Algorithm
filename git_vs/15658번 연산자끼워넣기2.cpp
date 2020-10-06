#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int minret = 1000000001;
int maxret = -1000000001;
int n;

void search(vector<int>& arr, int plus, int minus, int mul, int div, int depth, int ret) {
	if (depth == n - 1) {
		if (minret > ret)minret = ret;
		if (maxret < ret)maxret = ret;
		return;
	}
	int now = ret;
	if (plus > 0)search(arr, plus - 1, minus, mul, div, depth + 1, now + arr[depth + 1]);
	if (minus > 0)search(arr, plus, minus-1, mul, div, depth + 1, now - arr[depth + 1]);
	if (mul > 0)search(arr, plus, minus, mul-1, div, depth + 1, now * arr[depth + 1]);
	if (div > 0)search(arr, plus, minus, mul, div-1, depth + 1, now / arr[depth + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	int plus, minus, mul, div; cin >> plus >> minus >> mul >> div;

	search(arr, plus, minus, mul, div, 0, arr[0]);
	cout << maxret << "\n" << minret;
	return 0;
}