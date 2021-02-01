#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int answer = 0;
	int person = 0;
	vector<int> arr(n);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	while (person != k) {
		visited[person] = true;
		person = arr[person];
		answer++;
		if (visited[person]) {
			cout << "-1";
			return 0;
		}
	}
	cout << answer;
	return 0;
}