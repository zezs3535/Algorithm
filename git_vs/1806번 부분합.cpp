#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	int sum = 0;
	int answer = 100001;
	int st = 0;
	int end = 0;
	cin >> n >> s;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (1) {
		if (sum >= s) {
			answer = min(answer, st - end);
			sum -= arr[end];
			end++;
		}
		else if (sum < s) {
			sum += arr[st];
			st++;
		}
		if ((sum >= s && end == n) || (sum < s && st == n))break;
	}
	if (answer == 100001)cout << 0;
	else {
		cout << answer;
	}
	return 0;
}