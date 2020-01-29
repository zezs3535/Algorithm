#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector<int> v;
	int n, tmp;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	int max = 0;
	for (auto it = v.rbegin(); it != v.rend(); it++) {
		if (*it > max) {
			max = *it;
			answer++;
		}
	}
	cout << answer;
	return 0;
}