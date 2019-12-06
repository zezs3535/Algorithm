#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	deque<int> score;
	int tmp;
	int cnt = 1;
	for (int i = 0; i < 50; i++) {
		cin >> tmp;
		score.push_back(tmp);
	}
	int n;
	cin >> n;
	while (true) {
		if (score[0] == n)
			break;
		cnt++;
		score.pop_front();
	}
	if (cnt < 6)
		cout << "A+";
	else if (cnt < 16)
		cout << "A0";
	else if (cnt < 31)
		cout << "B+";
	else if (cnt < 36)
		cout << "B0";
	else if (cnt < 46)
		cout << "C+";
	else if (cnt < 49)
		cout << "C0";
	else
		cout << "F";

	return 0;
}