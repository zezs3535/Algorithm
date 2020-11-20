// 가장 긴 오름차순 수열 구하는 문제
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
	vector<pii> arr(n);
	vector<int> dp(n + 1, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if(arr[i].second>arr[j].second){
				dp[i] = max(dp[i], dp[j] + 1);
				answer = max(answer, dp[i]);
			}
		}
	}
	cout << n - answer;
	return 0;
}