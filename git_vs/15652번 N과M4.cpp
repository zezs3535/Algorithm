#include <bits/stdc++.h>

using namespace std;
int n, m;

void go(vector<int>& arr, vector<int>& num, int depth) {
	if (depth == m) {
		for (int j = 0; j < m-1; j++) {
			if (num[j] > num[j + 1])return;
		}
		for (int j = 0; j < m; j++) {
			cout << num[j] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!num[depth]) { //0이면 채워야지
			num[depth] = arr[i];
			go(arr, num, depth + 1);
			num[depth] = 0;
			if (i == n - 1)break;
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
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	go(arr, num, 0);

	return 0;
}