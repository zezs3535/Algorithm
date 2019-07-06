#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j, k;
	cin >> n;
	for (k = 1; k <= n; k++) { //1,2,3,4,5
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		for (j = 1; j <= 2 * (n - k); j++) {
			printf(" ");
		}
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		printf("\n");
	}
	for (k = n - 1; k > 0; k--) {//4,3,2,1
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		for (j = 1; j <= 2 * (n - k); j++) {
			printf(" ");
		}
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}