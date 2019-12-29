#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s = "";
	cin >> s;
	vector<int> sign;
	vector<int> num;
	int cur = 0;
	int ans = 0;
	bool isMinus = false;
	sign.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') { //���ڿ��� ��ȣ�϶�
			num.push_back(cur);
			cur = 0;
			if (s[i] == '+') {
				sign.push_back(1);
				continue;
			}
			else {
				sign.push_back(-1);
				continue;
			}
		}
		else { //���ڿ��� �����϶�
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			isMinus = true;
		}
		if (isMinus) {
			ans -= num[i];
			continue;
		}
		else {
			ans += num[i];
			continue;
		}
	}
	cout << ans;
	return 0;
}