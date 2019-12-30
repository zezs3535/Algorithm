#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int stu[100][10] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int cnt = 0;
	vector<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> stu[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (stu[i][j] == ((j % 5) + 1))
				cnt++;
		}
		if (cnt == 10)
			ans.push_back(i + 1);
	}
	for (int it : ans)
		cout << it << "\n";
	return 0;
}