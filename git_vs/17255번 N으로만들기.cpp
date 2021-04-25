//0~9���� ���� -> ���ʿ� 0~9���� ����
//					-> �����ʿ� 0~9���� ����
//string�� ���̰� n�� �Ǹ� set�� insert

//1Ʈ �ð��ʰ� -> �Է¹��� ���ڰ� �ʿ����� check�迭�� �����ؼ� �ʿ���� ���ڴ� Ž�� ���ϰ� �ϴ� ���
#include <bits/stdc++.h>
using namespace std;
set<string> s;
bool check[10] = { false, };
string n;

void solve(string ans, string anssum, int len) { //len�� �̹��� �߰��ؼ� ����ڰ� �Ǿ�����
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