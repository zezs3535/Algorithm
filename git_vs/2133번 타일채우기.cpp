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
		for (int i = 3; i <= n; i++) { //dp[n]�� dp[n-2]���� 3���� ������ �߰�
			// �׸��� Ư�� ���̽����� �߰��������.. dp[n]�� dp[n-4]���� 4ĭ�� �ѹ��� ������ �ְ�
			//dp[n]�� dp[n-6]���� 6ĭ�� �ѹ��� ������ �ְ�... �� üũ(for j)
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