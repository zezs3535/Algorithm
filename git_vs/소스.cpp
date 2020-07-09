#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<int> s;
	int heights[5] = { 6,9,5,7,4 };
	cout << heights[0];
	vector<int> ans;
	s.push(4);
	for (int i = 3; i > 0; i--) {
		if (s.top() < heights[i]) {
			while(s.top()<heights[i]&&!s.empty()){
				s.pop();
				ans.push_back(i + 1);
			}
		}
	}
	while (ans.size() != 5)ans.push_back(0);
	for (int i = 4; i > 0; i--)cout << ans[i];
	return 0;
}