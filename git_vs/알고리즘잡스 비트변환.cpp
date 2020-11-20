#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a; cin >> a;
	string b; cin >> b;
	int oneCntOfA = 0;
	int oneCntOfB = 0;
	int cntDiff = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1')oneCntOfA++;
		if (b[i] == '1')oneCntOfB++;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])cntDiff++;
	}
	cout << abs(oneCntOfA-oneCntOfB)+(cntDiff - (abs(oneCntOfA - oneCntOfB)))/2;
	return 0;
}