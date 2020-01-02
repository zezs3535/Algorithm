#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int getCnt(const vector<int> &a) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[i] == 2 * a[j] && a[i]!=1) {
				cnt++;
				break;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> a;
	int tmp=0;
	while (1) {
		cin >> tmp;
		if (tmp == -1)
			return 0;
		else if (tmp == 0) {
			cout<<getCnt(a)<<endl;
			a.clear();
			continue;
		}
		a.push_back(tmp);
	}

	return 0;
}