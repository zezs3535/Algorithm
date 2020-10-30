#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int arr[101] = { 0, };
	int reject = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (arr[tmp] >= 1)reject++;
		arr[tmp] += 1;
	}
	cout << reject;
	return 0;
}