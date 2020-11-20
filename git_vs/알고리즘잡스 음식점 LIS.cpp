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
	int answer = 0;
	int idx = 0;
	vector<int> arr(n);
	vector<int> dp(n, 1);
	vector<int> revdp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (arr[i] > arr[j]) {
				revdp[i] = max(revdp[i], revdp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (answer <= dp[i] + revdp[i]) {
			answer = max(answer, dp[i] + revdp[i]);
			idx = i;
		}
	}

	cout << "\n";
	cout << "dp : ";
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n\n";
	cout << "revdp : ";
	for (int i = 0; i < n; i++) {
		cout << revdp[i] << " ";
	}
	cout << "\n";

	cout << idx<<" "<<dp[idx]<<" "<<revdp[idx];
	return 0;
}