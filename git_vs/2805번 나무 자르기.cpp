#include <iostream>
#include <algorithm>

using namespace std;

long long len[1000001];
int N, M;
bool check(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		if(len[i]>=mid)
			cnt += len[i] - mid;
	}
	if (cnt >= M)
		return true;
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> len[i];
	long long _max = max(len[0], len[N-1]);
	long long l = 0;
	long long r = _max;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		//cout <<"l : "<<l<<" mid : "<<mid <<" r : "<<r<<" ans : " << ans << "\n";

		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}