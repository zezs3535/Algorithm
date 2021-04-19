#include <bits/stdc++.h>
#define MAX 500001
#define INTMAX 2147483647
using namespace std;
vector<int> suk(MAX,0);
vector<int> jong(MAX,0);
//석순은 ans면 종유석은 (H+1)-ans로 탐색
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, h; cin >> n >> h;
	int ans = INTMAX;
	int anscnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (i % 2 == 0)suk[tmp] += 1;
		else jong[tmp] += 1;
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = MAX - 1; i >= 0; i--) {
		cnt1 += suk[i];
		suk[i] = cnt1;
		cnt2 += jong[i];
		jong[i] = cnt2;
	}
	for (int i = 1; i <= h; i++) {
		int sukcnt = suk[i];
		int jongcnt = jong[(h+1)-i];
		if (ans > (sukcnt + jongcnt)) {
			ans = sukcnt + jongcnt;
			anscnt = 1;
		}
		else if (ans == (sukcnt + jongcnt)) {
			anscnt += 1;
		}
	}
	cout << ans << " " << anscnt;
	return 0;
}
