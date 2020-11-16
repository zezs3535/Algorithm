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
	int l = 0;
	int r = n - 1;
	int answer = 0; 

	vector<int> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];

	sort(arr.begin(), arr.end());
	
	while (l < r) {
		if (arr[l] + arr[r] > m) {
			r--;
		}
		else if (arr[l] + arr[r] < m) {
			l++;
		}
		else {
			answer++;
			l++;
			r--;
		}
	}
	cout << answer;
	return 0;
}