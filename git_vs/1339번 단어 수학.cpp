//1339�� �ܾ���� ����,
//GCF+ACDEB���� ������ 100G 1010C 1F 10000A �̷� ���׽����� ��Ÿ���� ���� �ٽ�

#include <bits/stdc++.h>

using namespace std;
int alphabet[26] = { 0, };

void getScore(string s) {
	int pos = 1;
	for (int i = s.size()-1; i >= 0; i--) {
		alphabet[s[i] - 'A'] += pos;
		pos *= 10;
	}
}
bool cmp(int& a, int& b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		getScore(s);
	}
	sort(alphabet, alphabet + 26, cmp);
	int idx = 9;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)break;
		ans += (idx * alphabet[i]);
		idx--;
	}
	cout << ans;
	return 0;
}