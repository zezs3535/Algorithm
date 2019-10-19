#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long w;
	long long coin = 0;
	int s[16]; //그날의 주가
	int a[16]; //기울기
	int cnt=0;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i < n; i++) {
		a[i] = s[i + 1] - s[i];
		if (a[i] > 0)
			cnt++;
	}
	if (!cnt)
		cout << w;
	else {
		for (int i = 1; i < n; i++) {
			if (a[i]>0) {
				if (coin)
					continue;
				else {
					coin = w / s[i];
					w %= s[i];
				}
			}
			else if (a[i]<0) {
				if (coin) {
					w = w + (coin * s[i]);
					coin = 0;
				}
			}
		}
		if (coin)
			w += (coin*s[n]);
		cout << w;
	}
	return 0;
}