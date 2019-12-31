#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, less<int> > p;
	int n;
	int op;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> op;
		if (!op) {
			if (p.empty())cout << 0 << "\n";
			else {
				cout <<p.top()<<"\n";
				p.pop();
			}
		}
		else {
			p.push(op);
		}
	}
	return 0;
}