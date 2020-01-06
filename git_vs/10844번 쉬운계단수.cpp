#include <iostream>
#define mod 1000000000
using namespace std;

int d[101][10] = { 0, };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int num;
	cin >> num;
	int sum = 0;
	for (int i = 1; i <= 9; i++) { //1자리 계단수는 1
		d[1][i] = 1;
	}
	d[1][0] = 0;
	for (int n = 2; n <= num; n++) { 
		for (int l = 0; l <= 9; l++) {
			if (1 <= l && l <= 8) d[n][l] += (d[n - 1][l - 1]+d[n-1][l+1]);
			else if (l == 0) d[n][l] += d[n - 1][l + 1];
			else if (l == 9) d[n][l] += d[n - 1][l - 1];
			d[n][l] %= mod;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		sum = (sum + d[num][i]) % mod;
	}
	cout << sum;
	return 0;
}