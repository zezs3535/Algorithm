//0~9까지 생성 -> 왼쪽에 0~9까지 생성
//					-> 오른쪽에 0~9까지 생성
//string의 길이가 n이 되면 set에 insert

//1트 시간초과 -> 입력받은 숫자가 필요한지 check배열을 생성해서 필요없는 숫자는 탐색 안하게 하니 통과
#include <bits/stdc++.h>
using namespace std;
set<string> s;
bool check[10] = { false, };
string n;

void solve(string ans, string anssum, int len) { //len은 이번에 추가해서 몇글자가 되었는지
	if (len == n.size()) {
		if (ans == n) {
			s.insert(anssum);
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i])solve(to_string(i) + ans, to_string(i) + ans + anssum, len + 1);
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i])solve(ans + to_string(i), to_string(i) + ans + anssum, len + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n.size(); i++) {
		check[n[i] - '0'] = true;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i])solve(to_string(i), to_string(i), 1);
	}

	cout << s.size();

	return 0;
}