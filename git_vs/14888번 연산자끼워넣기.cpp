#include <bits/stdc++.h>

using namespace std;

int n;
int a[101] = { 0, };
int maxret = -1000000001;
int minret = 1000000001;

void calc(int cnt, int cur, int plusop, int minusop, int mulop, int divop) {
	if (cnt==n-1) {
		if (maxret < cur)maxret = cur;
		if (minret > cur)minret = cur;
		return;
	}
	if (plusop != 0)calc(cnt + 1, cur+a[cnt+1], plusop - 1, minusop, mulop, divop);
	if (minusop != 0)calc(cnt + 1, cur - a[cnt + 1], plusop, minusop - 1, mulop, divop);
	if (mulop != 0)calc(cnt + 1, cur * a[cnt + 1], plusop, minusop, mulop - 1, divop);
	if (divop != 0)calc(cnt + 1, cur / a[cnt + 1], plusop, minusop, mulop, divop - 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int plusop, minusop, mulop, divop;
	cin >> plusop >> minusop >> mulop >> divop;
	calc(0, a[0], plusop, minusop, mulop, divop);
	cout << maxret << "\n" << minret;
	return 0;
}