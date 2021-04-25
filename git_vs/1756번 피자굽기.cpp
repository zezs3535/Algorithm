#include <bits/stdc++.h>

using namespace std;
vector<int> oven(300001, 1e9 + 10);
vector<int> pizza(300001, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int d, n; cin >> d >> n;
	int idx = 0;
	int ans = 0;
	stack<int> s;
	cin >> oven[0];
	for (int i = 1; i < d; i++) {
		int tmp; cin >> tmp;
		oven[i] = min(tmp, oven[i - 1]); //���ÿ� �ְ� �ڿ������� Ž���ϱ⶧����
		// �տ������� ������ ���ϴ� ���� ������ Ʋ���� �Ǵ���
		// ex) 5 5 6 7 3 2 2 -> 5 5 5 5 3 2 2 �̷������� ���� �־������
	}

	for (int i = 0; i < n; i++)cin >> pizza[i];

	for (int i = 0; i < d; i++) {
		if (oven[i] >= pizza[idx]) { //���쿡 ���� ������ ����
			s.push(oven[i]); //���ÿ� ���� ũ�⸦ �ְ�
		}
		else { //�ȵ���
			if (i == 0) {
				cout << 0;
				return 0;
			}
			break;
		}
	}
	while (!s.empty() && idx < n) {
		if (s.top() >= pizza[idx]) { //������ ������ ���� ���� ���� ���̰�
			ans = s.size();
			idx++;
		}
		s.pop(); //���쿡 �ɸ��� �Ȱɸ������� ������ pop.. ������ �״��
	}
	if (idx == n)cout << ans;
	else cout << 0;
	return 0;
}