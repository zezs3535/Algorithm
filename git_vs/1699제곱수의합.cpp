#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,min,temp;
	cin >> n;
	int *dp = new int[100001];
	for (int i = 0; i < 4; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		min = i;
		for (int j = 1; j*j <= i; j++) {
			if (i == j * j) {
				min = 1;
				break;
			}
			else {
				temp = dp[i - j * j] + 1;
				if (temp < min) {
					min = temp;
				}
			}
		}
		dp[i] = min;
	}
	printf("%d", dp[n]);

	return 0;
}