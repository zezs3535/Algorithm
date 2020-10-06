#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	vector<char> answer;
	stack<char> st;
	bool par = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			par = true;
			while (!st.empty()) {
				char tmp = st.top();
				answer.push_back(tmp);
				st.pop();
			}
			answer.push_back(s[i]);
			continue;
		}
		else if (s[i] == '>') {
			par = false;
			answer.push_back(s[i]);
			continue;
		}
		if (par) {
			answer.push_back(s[i]);
		}
		else{
			if (s[i] == ' ') {
				while (!st.empty()) {
					char tmp = st.top();
					answer.push_back(tmp);
					st.pop();
				}
				answer.push_back(' ');
				continue;
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		char tmp = st.top();
		answer.push_back(tmp);
		st.pop();
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}