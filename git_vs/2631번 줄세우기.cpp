#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 1);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])dp[i] = max(dp[j]+1, dp[i]);
			if (ans < dp[i])ans = dp[i];
		}
	}
	cout << n-ans;
	return 0;
}