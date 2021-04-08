#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	int ans = 0;
	int l = 0;
	int r = 0;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)cin >> arr[i];
	
	for (int i = 0; i < n; i++)r += arr[i];

	while (l <= r) {
		int cnt = 0;
		int sum = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			sum += arr[i]; //�� ������ ���� sum�� ����
			if (sum >= mid) {  //sum�� mid���� ũ�ų� �������� ������ �ϳ� ������
				sum = 0;
				cnt++; //����++
			}
		}
		if (cnt >= k) { //������ K���� ������ �����븦 ������ �� ���� ������ �����
			l = mid+1;
		}
		if (cnt < k) { //������ K���� ������ �����븦 ���缭 �� ���� ������ �����
			r = mid-1;
		}
		
	}
	cout << r; //���� r�� ������ .. l�� r���� �������ִٰ� while���� ������ ������ l�� r���� Ŀ����.. �������� l���� �ٲ�� r���� �״�δϱ� r���� ���
	return 0;
}