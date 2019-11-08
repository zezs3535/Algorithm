#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int cnt1 = 0;
	int cnt2 = 0;
	int n;
	int len = 0;
	cin >> s;
	cin >> n;
	for (int i = 0; i < s.size(); i++) {
		if (s[i]=='*')
			cnt1++;
		if (s[i] == '?')
			cnt2++;
	}
	len = s.size() - cnt2 - cnt1; //only alphabet
	if (cnt1) {
		if (n >= (len - cnt2))
			cout << "Possible";
		else
			cout << "Impossible";
	}
	else {
		if (n <= len && n >= (len - cnt2))
			cout << "Possible";
		else
			cout << "Impossible";
	}
	return 0;
}