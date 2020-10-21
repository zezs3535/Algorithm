#include <bits/stdc++.h>

using namespace std;
int n;
int ans = 0;
long long dp[21][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	vector<int> arr(n-1);
	for (int i = 0; i < n-1; i++) {
		cin >> arr[i];
	}
	cin >> ans;
	for (int i = 0; i <= 20; i++)fill(dp[i], dp[i] + 100, 0);
	dp[arr[0]][0] = 1;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[j][i] != 0) {
				int nextplus = j + arr[i + 1];
				int nextminus = j - arr[i + 1];
				if(nextplus<=20)dp[nextplus][i + 1] += dp[j][i];
				if(nextminus>=0)dp[nextminus][i + 1] += dp[j][i];
			}
		}
	}
	cout << dp[ans][n - 2];
	return 0;
}