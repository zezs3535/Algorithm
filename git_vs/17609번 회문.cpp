#include <bits/stdc++.h>
#define MAX 2147483647

using namespace std;
typedef pair<int, int> pii;
int ans;

void checksecond(int l, int r, string in) {
	while (l < r) {
		if (in[l] != in[r]) {
			return;
		}
		l++;
		r--;
	}
	ans = 1;
}
void checkfirst(string in) {
	int n = in.size();
	int l = 0;
	int r = n - 1;
	while (l < r) {
		if (in[l] != in[r]) {
			checksecond(l + 1, r, in);
			checksecond(l, r-1, in);
			return;
		}
		l++;
		r--;
	}
	ans = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test; cin >> test;
	while (test--) {
		string in; cin >> in;
		ans = 2;
		checkfirst(in);
		cout << ans << "\n";
	}
	return 0;
}