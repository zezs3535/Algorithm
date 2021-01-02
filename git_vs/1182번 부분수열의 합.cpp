#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s; cin >> n >> s;
	int ret = 0;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)cin >> arr[i];

	for (int i = 1; i < (1 << n); i++) {		
		//1<<n ��ŭ ���� ������ 5��Ʈ�� 00000 ~ 11111 ���� 2^5 (32)��ŭ ǥ���� �����ϱ� ����
		//00000 00001 00010 00011 .......... 11100  11101 11110 11111 ���� i�� ����, j�� 0���� n���� ��ĭ�� �̵��ϸ� ��ġ���� Ȯ��
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))sum += arr[j];
		}
		if (sum == s)ret++;
	}

	cout << ret;
	return 0;
}