#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int> > pq;
	int max = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	int size = pq.size();
	while (!pq.empty()) {
		if (max <= size * pq.top())max = size * pq.top();
		pq.pop();
		size--;
	}
	cout << max;
	return 0;
}