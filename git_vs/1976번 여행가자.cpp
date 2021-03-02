#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<int> tour(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> tour[i];
		tour[i]--;
	}
	for (int k = 0; k < n; k++) { //플로이드와샬
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] && arr[k][j])arr[i][j] = 1;
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < m - 1; i++) { //여행지 확인
		if (tour[i] == tour[i + 1])continue;
		if (arr[tour[i]][tour[i + 1]] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}