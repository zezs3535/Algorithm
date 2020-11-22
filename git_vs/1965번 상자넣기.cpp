#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	vector<int> dp(n, 1);
	int answer = 1;
	for (int i = 0; i < n; i++)cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				answer = max(answer, dp[i]);
			}
		}
	}
	cout << answer;
	return 0;
}