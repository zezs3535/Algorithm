#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string a,b;
	cin >> a >> b;
	int m = a.size();
	int n = b.size();
	vector<char> x(m+1);
	vector<char> y(n+1);
	vector<vector<int> >c(m+1, vector<int>(n+1, 0));
	for (int i = 1; i <= m; i++) {
		x[i] = a[i-1];
	}
	for (int i = 1; i <= n; i++) {
		y[i] = b[i-1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j])c[i][j] = c[i - 1][j - 1] + 1;
			else if (c[i - 1][j] >= c[i][j - 1])c[i][j] = c[i - 1][j];
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	//for (int i = 1; i <= m; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << c[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << c[m][n];
	return 0;
}