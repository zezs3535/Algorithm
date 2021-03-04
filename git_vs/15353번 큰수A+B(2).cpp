#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	string b;
	deque<char> answer;
	cin >> a >> b;
	int aIdx = a.size()-1;
	int bIdx = b.size()-1;
	int num = 0;
	int nextNum = 0;
	while (aIdx != -1 || bIdx != -1) {
		num = nextNum;
		if (aIdx != -1) {
			num += (a[aIdx] - '0');
			aIdx--;
		}
		if (bIdx != -1) {
			num += (b[bIdx] - '0');
			bIdx--;
		}
		nextNum = num / 10;

		num %= 10;
		answer.push_front(num+'0');
	}
	if (nextNum != 0)answer.push_front(nextNum+'0');
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}