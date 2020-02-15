#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s = 0;
	int m = 0;
	cin >> m;
	while (m--) {
		string op;
		int num;
		cin >> op;
		if (op == "add") {
			cin >> num;
			s = s | (1 << num);
		}
		else if (op == "remove") {
			cin >> num;
			s = s & ~(1 << num);
		}
		else if (op == "check") {
			cin >> num;
			if (s&(1 << num))cout << 1 << "\n";
			else {
				cout << 0 << "\n";
			}
		}
		else if (op == "toggle") {
			cin >> num;
			s = s ^ (1 << num);
		}
		else if (op == "all") {
			s = (1 << 21) - 1;
		}
		else if (op == "empty") {
			s = 0;
		}
	}
	return 0;
}