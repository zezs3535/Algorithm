#include <bits/stdc++.h>

using namespace std;

int num[10] = { 0, };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans(n);
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (cnt == num[i] && ans[j]==0) {
				ans[j] = i + 1;
				break;
			}
			if (ans[j] == 0 || ans[j] > i + 1)cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}