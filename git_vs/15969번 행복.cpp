#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> ans;
	int n,tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end());
	cout << ans[n - 1] - ans[0];
	return 0;
}