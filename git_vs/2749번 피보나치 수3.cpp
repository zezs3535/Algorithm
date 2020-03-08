#include <bits/stdc++.h>
#define pisano 1500000 //10^k로 나눈 피보나치 수는 15*10^(k-1)의 주기를 가진다
#define mod 1000000
using namespace std;

int fibo[pisano+1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int n;
	cin >> n;
	n %= pisano;
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= n; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%mod;
	}
	cout << fibo[n];
	return 0;
}