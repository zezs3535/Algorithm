#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    //DP[i] = i초일때 사용할 수 있는 스킬 조합의 수
    //값을 저장할 DP배열
    int dp[10001] = { 0, };

    cin >> n >> m;

    for (int i = 0; i <= m; i++) { //DP배열을 다 1로 초기화
        dp[i] = 1;
    }

    for (int i = m; i <= n; i++) { //i초일때는 i-1초에서 1초 걸리는 A스킬을 더 쓰거나
    //i-m초에서 m초 걸리는 B스킬을 더 쓰는 경우 두 가지 경우를 더한 값
        dp[i] = (dp[i - 1] % MOD + dp[i - m] % MOD) % MOD;
    }

    cout << dp[n];
    return 0;
}