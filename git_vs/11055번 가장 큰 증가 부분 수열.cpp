#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	vector<int> arr(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	ans = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i]<dp[j]+arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
			if (ans <= dp[i])ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}