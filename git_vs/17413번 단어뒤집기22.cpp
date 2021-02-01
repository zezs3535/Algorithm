#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	string answer = "";
	stack<char> st;
	bool flag = false;
	for (int i = 0; i < s.size();) {
		if (s[i] == '<') {
			while (!st.empty()) {
				char tmp = st.top();
				answer += tmp;
				st.pop();
			}
			answer += s[i];
			i++;
			while (s[i] != '>') {
				answer += s[i];
				i++;
			}
			answer += s[i];
			i++;
		}
		else {
			if (s[i] == ' ') {
				while (!st.empty()) {
					char tmp = st.top();
					answer += tmp;
					st.pop();
				}
				answer += s[i];
				i++;
				continue;
			}
			st.push(s[i]);
			i++;
		}
	}
	while (!st.empty()) {
		char tmp = st.top();
		answer += tmp;
		st.pop();
	}
	cout << answer;
	return 0;
}