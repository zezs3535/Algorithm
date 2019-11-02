#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	queue<char> c;
	stack<int> s;
	int T,n,temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		q.push(n);
	}
	for (int i = 1; i <= T; i++) {
		s.push(i);
		c.push('+'); //push를 char형 queue에 넣어놓기
		while (!s.empty()) {
			if (s.top() == q.front()) {
				
				s.pop(); q.pop();
				c.push('-'); //pop을 넣어놓기
				
			}
			else
				break;
		}
	}
	if (!s.empty()) {
		cout << "NO";
		return 0;
	}
	n = c.size();
	for (int i = 0; i < n; i++) {
		cout << c.front()<<"\n";
		c.pop();
	}
	return 0;
}