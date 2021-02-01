#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int answer = 0;
	for (int i = 1; i <= int(sqrt(n)); i++) {
		for (int j = i * i; j <= n; j=j+i) {
			answer++;
		}
	}
	cout << answer;
	return 0;
}