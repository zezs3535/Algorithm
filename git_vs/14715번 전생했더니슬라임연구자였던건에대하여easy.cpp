#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int key = 2;
	int cnt = 0;

	while (n > 1) {
		if (n % key == 0) {
			n /= key;
			cnt++;
			continue;
		}
		key++;
	}
	cout << ceil(log(cnt)/log(2));
	return 0;
}