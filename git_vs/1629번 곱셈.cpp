#include <bits/stdc++.h>

using namespace std;

long long func(int a, int b, int c) {
	if (b == 1)return a % c;
	if (b % 2 == 0) {
		return ((func(a%c, b / 2, c)%c)* (func(a%c, b / 2, c)%c))%c;
	}
	else {
		return ((func(a%c, b / 2, c)%c) * (func(a%c, b / 2, c)%c))%c * (a % c);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout<<func(a%c, b, c)%c;
	return 0;
}