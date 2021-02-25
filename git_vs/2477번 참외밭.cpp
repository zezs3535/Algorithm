#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	int maxGa = 0;
	int maxSe = 0;
	int maxGaIdx = -1;
	int maxSeIdx = -1;
	int mul = 1;
	vector<pii> line(6);
	vector<bool> chk(6, false);
	for (int i = 0; i < 6; i++) {
		cin >> line[i].first >> line[i].second;
		if (line[i].first <3 && maxGa < line[i].second) {
			maxGa = line[i].second;
			maxGaIdx = i;
		}
		if (line[i].first>2 && maxSe < line[i].second) {
			maxSe = line[i].second;
			maxSeIdx = i;
		}
	}
	chk[(maxGaIdx + 1) % 6] = true;
	chk[maxGaIdx] = true;
	if (maxGaIdx == 0) {
		chk[5] = true;
	}
	else {
		chk[maxGaIdx - 1] = true;
	}
	chk[(maxSeIdx + 1) % 6] = true;
	chk[maxSeIdx] = true;
	if (maxSeIdx == 0) {
		chk[5] = true;
	}
	else {
		chk[maxSeIdx - 1] = true;
	}
	for (int i = 0; i < 6; i++) {
		if (!chk[i])mul *= line[i].second;
	}
	cout << ((maxGa * maxSe) - mul) * n;
	return 0;
}