#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int sum, cnt, test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> s;
		cnt = 0;
		sum = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				cnt++;
				sum += cnt;
				continue;
			}
			cnt = 0;
		}
		cout << sum << "\n";
	}
	return 0;
}