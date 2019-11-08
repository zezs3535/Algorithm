//comment only english

#include <iostream>
#include <string>
using namespace std;

int cal[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			sum += cal[0];
		else if (s[i] == '2')
			sum += cal[1];
		else if (s[i] == '3')
			sum += cal[2];
		else if (s[i] == '4')
			sum += cal[3];
	}
	cout << sum;

	return 0;
}