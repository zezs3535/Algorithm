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
	if (n == 1) {
		cout << "*";
		return 0;
	}
	else {
		for (int i = 0; i < n*2; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0)cout << "*";
				else {
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}