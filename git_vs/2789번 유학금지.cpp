#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	deque<char> s;
	int cnt = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' ||
			str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') {
			continue;
		}
		s.push_back(str[i]);
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		cout << s[i];
	}
	return 0;
}