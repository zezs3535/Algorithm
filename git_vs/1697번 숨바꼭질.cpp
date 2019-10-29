#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	int map[100001] = { 0, };
	int N, K;
	int c = 0;
	cin >> N >> K;
	if (N == K) {
		cout << "0";
		return 0;
	}
	q.push(N); //���� ��ġ�� �ְ�
	while (!q.empty()) { //N-1, N+1, N*2���� ������Ű�鼭 K�� 0�� �ƴҶ� ���
		c = q.front();
		q.pop();
		if ((c - 1) >= 0 && (c - 1) <= 100000 && map[c-1]==0 ) {
			map[c - 1] = map[c] + 1;
			q.push(c - 1);
		}
		if ((c + 1) >= 0 && (c + 1) <= 100000 && map[c + 1] == 0) {
			map[c + 1] = map[c] + 1;
			q.push(c + 1);
		}
		if ((c * 2) >= 0 && (c * 2) <= 100000 && map[c * 2] == 0) {
			map[c * 2] = map[c] + 1;
			q.push(c * 2);
		}
		if (map[K])
			break;
	}
	cout << map[K];
	return 0;
}