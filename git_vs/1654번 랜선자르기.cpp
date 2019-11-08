#include <iostream>
#include <algorithm>

using namespace std;

long long len[10001];
int K, N;

bool check(long long mid) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += len[i] / mid;
	}
	if (cnt >= N)
		return true;
	else
		return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> K >> N;
	for (int i = 0; i < K; i++)cin >> len[i];
	long long _max = max(len[0],len[K-1]);
	long long l=1;
	long long r = _max;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}