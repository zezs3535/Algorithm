#include <bits/stdc++.h>
#define MAX 2147483647

using namespace std;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, b;
	int cnt = 0;
	int ans = MAX;
	cin >> n >> k >> b;
	vector<int> arr(n+1,0); //0정상 1고장
	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = 1;
	}
	for (int i = 1; i <= k; i++) {
		if (arr[i])cnt++;
	}
	ans = min(ans, cnt);
	for (int i = 1; i <= n - k; i++) {
		if (arr[i])cnt--;
		if (arr[i + k])cnt++;
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}