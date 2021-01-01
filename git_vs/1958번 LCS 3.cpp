#include <bits/stdc++.h>

using namespace std;

void getLCS(string a, string b, string c) {
	int m = a.size();
	int n = b.size();
	int k = c.size();
	vector<char> x(m + 1);
	vector<char> y(n + 1);
	vector<char> z(k + 1);
	//vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
	int arr[101][101][101] = { 0, };
	for (int i = 1; i <= m; i++) {
		x[i] = a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		y[i] = b[i - 1];
	}
	for (int i = 1; i <= k; i++) {
		z[i] = c[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= k; l++) {
				if (x[i] == y[j] && y[j] == z[l])arr[i][j][l] = arr[i - 1][j - 1][l - 1] + 1;
				else {
					arr[i][j][l] = max(arr[i - 1][j][l], max(arr[i][j - 1][l], arr[i][j][l - 1]));
				}
			}
		}
	}
	cout << arr[m][n][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	
	getLCS(a, b, c);

	return 0;
}