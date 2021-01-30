#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int n, m;

void rotate(vector<vector<int>>& arr, vector<vector<int>>& arr2, int idx) {
	if (idx % 2 == 0) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr2[i][j] = arr[n - 1 - j][i];
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = arr2[m - 1 - j][i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int answer = n * m * 2;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> arr2(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				answer += arr[j][0];
				for (int k = 1; k < m; k++) {
					if (arr[j][k] > arr[j][k - 1]) {
						answer += (arr[j][k] - arr[j][k - 1]);
					}
				}
			}
		}
		else if (i % 2 == 1) {
			for (int j = 0; j < m; j++) {
				answer += arr2[j][0];
				for (int k = 1; k < n; k++) {
					if (arr2[j][k] > arr2[j][k - 1]) {
						answer += (arr2[j][k] - arr2[j][k - 1]);
					}
				}
			}
		}
		rotate(arr, arr2, i);
	}
	cout << answer;
	return 0;
}