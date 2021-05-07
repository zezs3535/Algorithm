#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int dp[31] = { 0, };
	
	dp[1] = 0;
	dp[2] = 3;
	if (n > 2) {
		for (int i = 3; i <= n; i++) { //dp[n]은 dp[n-2]에서 3가지 종류를 추가
			// 그리고 특이 케이스들을 추가해줘야함.. dp[n]은 dp[n-4]에서 4칸을 한번에 먹을수 있고
			//dp[n]은 dp[n-6]에서 6칸을 한번에 먹을수 있고... 다 체크(for j)
			dp[i] = 0;
			if (i % 2 == 0) {
				dp[i] = dp[i - 2] * 3 + 2;
				for (int j = i - 4; j >= 0; j -= 2) {
					dp[i] += dp[j] * 2;
				}
			}
		}
	}
	cout << dp[n];
	return 0;
}