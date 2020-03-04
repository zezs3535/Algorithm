#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	int ans = 1;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (ans <= dp[i])ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}