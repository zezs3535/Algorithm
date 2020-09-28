#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<pii> home;
	vector<pii> chicken;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			int tmp; cin >> tmp;
			if (tmp == 1)home.push_back({ i,j });
			if (tmp == 2)chicken.push_back({ i,j });
		}
	}
	int l = chicken.size();
	vector<int> choice(l, 0);
	fill(choice.begin() + (l - m), choice.end(), 1);
	int answer = 1000000;
	do {
		int tmp = 0;
		for (auto h : home) {
			int ret = 100000;
			for (int i = 0; i < l; i++) {
				if (!choice[i])continue;
				ret = min(ret, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
			}
			tmp += ret;
		}
		answer = min(answer, tmp);
	} while (next_permutation(choice.begin(), choice.end()));
	cout << answer;
	return 0;
}