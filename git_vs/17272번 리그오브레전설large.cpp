#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long n;
int m;

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> tmp(m, vector<long long>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			long long value = 0;
			for (int k = 0; k < m; k++) {
				value += ((a[i][k] * b[k][j]) % MOD);
			}
			tmp[i][j] = value % MOD;
		}
	}
	return tmp;
}
//vector<vector<long long>> go(vector<vector<long long>>& arr, long long n) {
//	vector<vector<long long>> tmp(m, vector<long long>(m, 0));
//	if (n == 1) {
//		return arr;
//	}
//	if (n % 2 == 0) {
//		vector<vector<long long>> tmp2 = go(arr, n / 2);
//		tmp = mul(tmp2, tmp2);
//		tmp2.clear();
//	}
//	else {
//		tmp = mul(go(arr, n - 1), arr);
//	}
//	return tmp;
//}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<long long>> arr(m, vector<long long>(m, 0));
	vector<vector<long long>> ans(m, vector<long long>(m, 0));
	arr[0][0] = 1;
	arr[0][m - 1] = 1;
	for (int i = 1; i < m; i++) {
		arr[i][i - 1] = 1;
	}
	for (int i = 0; i < m; i++)ans[i][i] = 1;
	n = n - m + 1;
	while (n > 0) {
		if (n % 2 == 1) {
			ans = mul(ans, arr);
		}
		arr = mul(arr, arr);
		n /= 2;
	}
	//ans = go(arr, n-m+1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	long long answer = 0;
	for (int i = 0; i < m; i++) {
		answer += (ans[0][i] % MOD) % MOD;
	}
	cout << answer%MOD;
	return 0;
}