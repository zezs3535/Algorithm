#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int answer = 987654321;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<int> sel(n, 0);
	fill(sel.begin()+n/2, sel.end(), 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	do {
		int sTeam = 0;
		int lTeam = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (sel[i] == 0 && sel[j] == 0)sTeam += arr[i][j];
				else if (sel[i] == 1 && sel[j] == 1)lTeam += arr[i][j];
			}
		}
		answer = min(answer, abs(sTeam - lTeam));
	} while (next_permutation(sel.begin(), sel.end()));
	cout << answer;
	return 0;
}