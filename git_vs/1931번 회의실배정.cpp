#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	//���� ������ ����� �Լ�,
	//a�� b�� ������ �ð��� ������ ���۽ð��� ������������ �����Ѵ�
	//�װ� �ƴϸ� �����½ð� �������� ����
	if (a.second == b.second)return a.first < b.first;
	else {
		return a.second < b.second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0;
	int now = 0;
	cin >> n;
	vector<pair<int, int>> a(n); //pair<int,int>�� �ڷ������� �ϴ� vector n�� ����
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (now <= a[i].first) {
			now = a[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}