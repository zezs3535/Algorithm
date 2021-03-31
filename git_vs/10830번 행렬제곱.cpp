#include <bits/stdc++.h>

using namespace std;

int n;
long long m;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> tmp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int value = 0;
			for (int k = 0; k < n; k++) {
				value += ((a[i][k] * b[k][j])%1000);
			}
			tmp[i][j] = value%1000;
		}
	}
	return tmp;
}
vector<vector<int>> go(vector<vector<int>>& arr, long long m) {
	vector<vector<int>> tmp(n, vector<int>(n, 0));
	if (m == 1) {
		return arr;
	}
	else if (m == 2) {
		tmp = mul(arr, arr);
	}
	if (m % 2 == 0) {
		vector<vector<int>> tmp2 = go(arr, m / 2);
		tmp = mul(tmp2, tmp2);
		tmp2.clear();
	}
	else {
		tmp = mul(go(arr, m - 1), arr);
	}
	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	ans = go(arr, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j]%1000 << " ";
		}
		cout << "\n";
	}
	return 0;
}