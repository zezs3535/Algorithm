#include <bits/stdc++.h>

using namespace std;

int arr[101][101] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int xx = x; xx < x + 10; xx++) {
			for (int yy = y; yy < y + 10; yy++) {
				arr[yy][xx] = 1;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j])answer += 1;
		}
	}
	cout << answer;
	return 0;
}