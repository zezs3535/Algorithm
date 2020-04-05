#include <bits/stdc++.h>

using namespace std;
int n, m;

void func(vector<int> &arr, vector<bool> &use, int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	/* �� ĭ�� 1~n�� ��ͷ� ���� ������� �ʾ����� T�� �ٲٰ� �迭�� �ְ�,
	����ϰ� ������ F�� �ٲ㼭 ���������� �湮�� �� �ֵ��� �Ѵ�.
	*/
	for (int i = 0; i < n; i++) { 
		if (!use[i]) { //������� �ʾ�����
			arr[k] = i+1; //k��° ���� i+1 �ֱ�
			use[i] = true;
			func(arr, use, k + 1);
			use[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<bool> use(n, false);
	vector<int> arr(m);
	func(arr, use, 0);
	
	return 0;
}