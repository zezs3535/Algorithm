#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (cnt == 0&&s[i]=='U')cnt++;
		if (cnt == 1 && s[i] == 'C')cnt++;
		if (cnt == 2 && s[i] == 'P')cnt++;
		if (cnt == 3 && s[i] == 'C')cnt++;
		if (cnt == 4) {
			cout << "I love UCPC";
			return 0;
		}
	}
	cout << "I hate UCPC";
	return 0;
}