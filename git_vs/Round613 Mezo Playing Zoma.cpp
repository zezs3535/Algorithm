#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s = "";
	int n;
	int L = 0;
	int R = 0;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L')L--;
		else {
			R++;
		}
	}
	cout << R - L + 1;
	return 0;
}