#include <bits/stdc++.h>

using namespace std;

vector<char> p;
void print(vector<vector<int> > &q, vector<char> &x, int i, int j) {
	if (i == 0 || j == 0)return;
	if (q[i][j] == 2) {
		print(q, x, i - 1, j - 1);
		p.push_back(x[i]);
	}
	else if (q[i][j] == 3)print(q, x, i - 1, j);
	else {
		print(q, x, i, j - 1);
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int m = a.size();
	int n = b.size();
	vector<char> x(m + 1);
	vector<char> y(n + 1);
	vector<vector<int> >c(m + 1, vector<int>(n + 1, 0));
	vector<vector<int> >q(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		x[i] = a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		y[i] = b[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				q[i][j] = 2;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				q[i][j] = 3;
			}
			else {
				c[i][j] = c[i][j - 1];
				q[i][j] = 1;
			}
		}
	}
	print(q, x, m, n);
	//cout << c[m][n] << "\n";
	for (int i = 0; i < p.size(); i++) {
		cout << p[i];
	}
	return 0;
}