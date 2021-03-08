#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	vector<pii> map(100001);
	int N, K;
	int c = 0;
	cin >> N >> K;
	if (N == K) {
		cout << "0\n"<<N;
		return 0;
	}
	q.push(N); //���� ��ġ�� �ְ�
	while (!q.empty()) { //N-1, N+1, N*2���� ������Ű�鼭 K�� 0�� �ƴҶ� ���
		c = q.front();
		q.pop();
		if ((c - 1) >= 0 && (c - 1) <= 100000 && map[c - 1].first == 0) {
			map[c - 1].first = map[c].first + 1;
			map[c - 1].second = c;
			q.push(c - 1);
		}
		if ((c + 1) >= 0 && (c + 1) <= 100000 && map[c + 1].first == 0) {
			map[c + 1].first = map[c].first + 1;
			map[c + 1].second = c;
			q.push(c + 1);
		}
		if ((c * 2) >= 0 && (c * 2) <= 100000 && map[c * 2].first == 0) {
			map[c * 2].first = map[c].first + 1;
			map[c * 2].second = c;
			q.push(c * 2);
		}
		if (map[K].first) {
			break;
		}
	}
	cout << map[K].first << "\n";
	int start = K;
	stack<int> order;
	order.push(K);
	while (start != N) {
		order.push(map[start].second);
		start = map[start].second;
	}
	while (!order.empty()) {
		cout << order.top() << " ";
		order.pop();
	}
	return 0;
}