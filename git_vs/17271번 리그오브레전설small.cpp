#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    //DP[i] = i���϶� ����� �� �ִ� ��ų ������ ��
    //���� ������ DP�迭
    int dp[10001] = { 0, };

    cin >> n >> m;

    for (int i = 0; i <= m; i++) { //DP�迭�� �� 1�� �ʱ�ȭ
        dp[i] = 1;
    }

    for (int i = m; i <= n; i++) { //i���϶��� i-1�ʿ��� 1�� �ɸ��� A��ų�� �� ���ų�
    //i-m�ʿ��� m�� �ɸ��� B��ų�� �� ���� ��� �� ���� ��츦 ���� ��
        dp[i] = (dp[i - 1] % MOD + dp[i - m] % MOD) % MOD;
    }

    cout << dp[n];
    return 0;
}