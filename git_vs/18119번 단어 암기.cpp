#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> query(n,0);
	int alpha;
	for (int i = 0; i < 26; i++) {
		alpha |= (1 << i);    //alpha�� 111111111111111111111 �� ���� �ش�
	}

	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			query[i] |= 1 << (tmp[j]-'a');	//���ڿ����� int�� ��Ʈ����ŷ
		}
	}

	for (int i = 0; i < m; i++) {
		int cnt = 0;
		int o;
		char x;
		cin >> o >> x;
		alpha ^= 1 << (x - 'a');      //o�� 1�϶� x�� ����ϰ� �ִ��� ����, o�� 0�϶� x�� �ذ��ִ��� ����Ǳ� ������
										  //o�� ���� ������� 1<<(x-'a')�� ���������ָ� �ȴ�
		for (int j = 0; j < n; j++) { 
			if ((query[j] & alpha) == query[j]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}