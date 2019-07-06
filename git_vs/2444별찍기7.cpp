#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,i,j,k;
	cin >> n;
	for (k = 1; k <= n; k++) { //1,2,3,4,5
		for (i = n; i > k; i--) {
			printf(" "); //5,4,3,2,1
		}
		for (j = 1; j <= 2*k-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (k = n - 1; k > 0; k--) {//4,3,2,1
		for (i = 0; i < n-k; i++) { //1,2,3,4
			printf(" ");
		}
		for (j = 1; j <= 2 * k - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}