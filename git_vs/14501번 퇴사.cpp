#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
int dp[17] = { 0, };
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pii> price(n+2);
	for (int i = 1; i <= n; i++) {
		cin >> price[i].first;
		cin >> price[i].second;
	}
	for (int i = n; i > 0; i--) {
		if (i + price[i].first > n + 1) {
			dp[i] = dp[i + 1];
		}
		else { /* dp[2]�� �����ϸ� 5���� �ɸ���. dp[6]���� ���� ���ϴ�
			   max(dp[3],p[2]+dp[7])�� �ϴ� ��
			   */
			dp[i] = max(dp[i + 1], dp[i + price[i].first] + price[i].second);
		}
	}
	cout << dp[1] << endl;
	return 0;
}