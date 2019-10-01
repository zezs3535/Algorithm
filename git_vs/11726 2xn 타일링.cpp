#include <iostream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int a[501][501];
int sum[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int n;
	//cin >> n;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		cin >> a[i][j];
	//	}
	//}
	//memset(sum, -1, sizeof(sum));
	int num3 = 30, num4 = 40;
	int& ref = num3;
	ref = 300;
	num4 = ref;
	ref = 400;
	cout << num3 << " " << num4<<" " << ref;
	return 0;
}