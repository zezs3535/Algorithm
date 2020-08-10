#include <bits/stdc++.h>

using namespace std;

struct pos {
	int value;
	int idx;
	int ans = 0;
};

bool cmp(pos& a, pos& b) {
	return a.value < b.value;
}

bool cmp2(pos& a, pos& b) {
	return a.idx < b.idx;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<pos> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i].value;
		num[i].idx = i;
	}
	sort(num.begin(), num.end(), cmp);
	int minidx=num[0].value;
	int cnt = 0;
	for (int i = 1; i < num.size(); i++) {
		if (num[i].value != minidx) {
			num[i].ans = ++cnt;
			minidx = num[i].value;
		}
		else {
			num[i].ans = cnt;
		}
	}
	sort(num.begin(), num.end(), cmp2);
	for (int i = 0; i < n; i++)cout << num[i].ans << " ";
	return 0;
}