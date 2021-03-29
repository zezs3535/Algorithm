#include <bits/stdc++.h>
#define n(i) s[i]-'0'
#define MOD 1000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	if (s[0] == '0') {
		cout << 0;
		return 0;
	}
	int ans = 0;
	int dp[5002] = { 0, };
	dp[0] = 1;
	dp[1] = 1;
	if ((n(0)<=2 && n(1)<=6) || (n(0)<=1 && n(1)<=9))dp[1] = 2;
	if (n(1) == 0)dp[1]--;
	
	for (int i = 2; i < s.size(); i++) {
		if ((n(i - 1) >= 1 && n(i - 1) <= 2 && n(i) <= 6) || (n(i-1)==1 && n(i)<=9)) {
			dp[i] = (dp[i]%MOD+dp[i - 2]%MOD)%MOD;
			
		}
		if (n(i) == 0)continue;
		dp[i] = (dp[i]%MOD+dp[i - 1]%MOD)%MOD;
	}
	cout << dp[s.size()-1];
	return 0;
}
