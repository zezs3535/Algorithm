#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;
	int cnt = 0;
	string s;
	getline(cin, s);
	string comp;
	getline(cin, comp);
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == comp[idx] && i+comp.size()<=s.size()) {
			while (s[i + idx] == comp[idx]) {
				idx++;
				cnt++;
				if (idx == comp.size())break;
			}
			if (cnt == comp.size()) {
				answer++;
				i += cnt - 1;
			}
		}
		idx = 0; cnt = 0;
	}
	cout << answer;
	return 0;
}