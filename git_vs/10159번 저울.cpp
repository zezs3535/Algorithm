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
	for (int i = 0; i < n; i++) { //플로이드 돌리고 반대방향도 체크
		for (int j = 0; j < n; j++) {
			if (arr[i][j])arr[j][i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (!arr[i][j])cnt++;
		}
		answer.push_back(cnt);
	}
	for (int i : answer)cout << i << "\n";
	return 0;
}