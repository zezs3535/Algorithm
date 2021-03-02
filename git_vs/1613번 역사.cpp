#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<int> answer;
	for (int i = 0; i < m; i++) {
		int q, w; cin >> q >> w;
		arr[q - 1][w - 1] = 1;
	}
	for (int k = 0; k < n; k++) { //플로이드와샬
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] && arr[k][j])arr[i][j] = 1;
			}
		}
	}
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int q, w; cin >> q >> w;
		q--; w--;
		if (arr[q][w])cout << "-1\n";
		else if (!arr[q][w] && arr[w][q])cout << "1\n";
		else if (!arr[q][w] && !arr[w][q])cout << "0\n";
	}
	return 0;
}