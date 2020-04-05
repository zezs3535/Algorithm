#include <bits/stdc++.h>

using namespace std;
string str;

bool isLaser(int n) {
	if (str[n] == '('&&str[n + 1] == ')')return true;
	else return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> str;
	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < str.size()-1; i++) {

		if (str[i] == '(') {
			if (isLaser(i)) {
				if(cnt>0)answer += cnt;
				i++;
				continue;
			}
			cnt++;
		}
		else {
			answer++;
			cnt--;
		}
	}
	if(isLaser(str.size()-2))cout << answer;
	else {
		cout << answer + 1;
	}
	return 0;
}