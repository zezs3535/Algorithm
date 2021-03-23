#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<char> s;
	string tmp; cin >> tmp;
	int bombCnt = 0;
	for (int i = 0; i < tmp.size(); i++) {
		s.push_back(tmp[i]);
	}

	string bomb; cin >> bomb;
	s.push_back(',');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.')continue;
		int idx = 0;
		int hit = 0;
		while (s[i + idx] == bomb[hit] || s[i+idx]=='.') { //계속 같으면
			if (s[i + idx] == ',')break;
			if (s[i + idx] != '.')hit++;
			idx++;
		}
		if (hit == bomb.size()) { //터지면?
			for (int j = 0; j < idx; j++) {
				s[i + j] = '.';
			}
			bombCnt++;
			i -= bomb.size()*bombCnt;
			if (i <= 0)i = -1;
		}
	}
	bool flag = false;
	string answer = "";
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] != '.') {
			flag = true;
			answer += s[i];
		}
	}
	if (flag) {
		cout << answer;
	}
	else {
		cout << "FRULA";
	}
	return 0;
}