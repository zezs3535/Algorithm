#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string in; cin >> in;
	string bomb; cin >> bomb;
	string s = "";
	for (int i = 0; i < in.size(); i++) {
		int idx = i;
		s.push_back(in[i]); //�ѱ��� �ְ�
		if (bomb[bomb.size() - 1] == in[i]) { //���� ������ ��ź �� �ڶ� ������?
			bool canBomb = true;
			for (int j = 0; j < bomb.size(); j++) {
				if(s.size()-1<j){
					canBomb = false;
					break;
				}
				if (s[s.size()-1 - j] != bomb[bomb.size() - 1 - j]) {
					canBomb = false;
					break;
				}
			}
			if (canBomb) {
				for (int j = 0; j < bomb.size(); j++) {
					s.pop_back();
				}
			}
		}
	}
	if (s.empty())cout << "FRULA";
	else {
		cout << s;
	}
	return 0;
}