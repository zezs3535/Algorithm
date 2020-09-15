#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int n;

bool promising(vector<int>& arr, int depth) {
	if (depth == 0)return true;
	for (int i = 0; i < depth; i++) {
		if (arr[depth] == arr[i] || (abs(arr[depth] - arr[i]) == abs(depth - i))) {
			return false;
		}
	}
	return true;
}

void search(vector<int>& arr, int depth) {
	if (depth == n)cnt++;
	else {
		for (int i = 0; i < n; i++) {
			arr[depth] = i;
			if (promising(arr, depth)) {
				search(arr, depth + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> arr(n, 0);
	search(arr, 0);
	cout << cnt;
	return 0;
}