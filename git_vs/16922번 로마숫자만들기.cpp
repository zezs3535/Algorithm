#include <bits/stdc++.h>

using namespace std;

int arr[4] = { 1,5,10,50 }; //�θ� ���� 4�� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n; //����� �� �ִ� ������ ����
	queue<int> q; //�θ� ���� 1,5,10,50�� �̿��Ͽ� ������ �� �� �����ϴ� queue
	set<int> tmp; //������ �� ���� �����ϴ� set (�ߺ� ����)
	for (int i = 0; i < 4; i++)q.push(arr[i]); //�θ� ���� 1 5 10 50�� q�� �־���´�
	for (int i = 1; i < n; i++) { //����� �� �ִ� ������ ������ŭ ����
		while (!q.empty()) { //���� queue�� �ִ� �� + 1, +5, +10, +50
			int cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				tmp.insert(cur + arr[j]); //������ ���� set�� �����Ͽ� �ߺ� ����
			}
		}
		for (auto it = tmp.begin(); it != tmp.end();it++) {
			q.push(*it); //set�� �ִ� ���� queue�� �ű�
		}
		tmp.clear();
	}
	cout << q.size();
	return 0;
}