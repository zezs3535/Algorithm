#include <bits/stdc++.h>

using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int answer = 0;
	stack<char> cnt;
	for (int i = 0; i < s.size(); i++) {
		if (cnt.empty())cnt.push(s[i]);
		else {
			if (cnt.top() == s[i] - 1)cnt.push(s[i]);
			else {
				if (cnt.size() == 3)answer++;
				while (!cnt.empty())cnt.pop();
				cnt.push(s[i]);
			}
		}
	}
	if (cnt.size() == 3)answer++;
	cout << answer;
	return 0;
}
