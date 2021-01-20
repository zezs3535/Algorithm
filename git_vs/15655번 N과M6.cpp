#include <bits/stdc++.h>

using namespace std;
int n, m;

void go(vector<int>& arr, vector<int>& num, vector<bool>& used, int depth) {
	if (depth == m) {
		for (int j = 0; j < m - 1; j++) {
			if (num[j] > num[j + 1])return;
		}
		for (int j = 0; j < m; j++) {
			cout << num[j] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) { //0이면 채워야지
			used[i] = true;
			num[depth] = arr[i];
			go(arr, num, used, depth + 1);
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> arr(n, 0);
	vector<int> num(m, 0);
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	go(arr, num, used, 0);

	return 0;
}