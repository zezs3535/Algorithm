#include <iostream>
#include <algorithm>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int dp[1000001];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	if (n > 3) {
		for (int i = 4; i <= n; i++) {
			vector<int> check;
			check.push_back(dp[i - 1]);
			if (i % 2 == 0) //2�� ���������� dp[i/2]�� ���� check�� ���� ( ������ �������� min���� +1 �ϴϱ� )
				check.push_back(dp[i / 2]);
			if (i % 3 == 0) //2�� ������������ ����
				check.push_back(dp[i / 3]);
			dp[i] = *min_element(check.begin(), check.end()) + 1;
		}
	}
	

	cout << dp[n];
	return 0;
}