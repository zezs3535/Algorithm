#include <iostream>
#include <vector>
using namespace std;
struct node {
	bool isVisit = false;
	int num;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int totalNode = (1 << n) - 1;
	vector<node> arr(totalNode);
	vector<vector<int>> level(n, vector<int>());
	for (int i = 0; i < totalNode; i++)cin >> arr[i].num;
	int curLevel = n - 1;
	for (int t = 0; t < n; t++) {
		int len = totalNode;
		int cnt = -1;
		for (int i = 0; i < len; i++) {
			if (!arr[i].isVisit) {
				cnt++;
				if (cnt % 2 == 0) {
					level[curLevel].push_back(arr[i].num);
					arr[i].isVisit = true;
				}
			}
		};
		curLevel--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < level[i].size(); j++) {
			cout << level[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}