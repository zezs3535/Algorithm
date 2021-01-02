#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s; cin >> n >> s;
	int ret = 0;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)cin >> arr[i];

	for (int i = 1; i < (1 << n); i++) {		
		//1<<n 만큼 도는 이유는 5비트면 00000 ~ 11111 까지 2^5 (32)만큼 표현이 가능하기 때문
		//00000 00001 00010 00011 .......... 11100  11101 11110 11111 까지 i를 돌며, j를 0부터 n까지 한칸씩 이동하며 겹치는지 확인
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))sum += arr[j];
		}
		if (sum == s)ret++;
	}

	cout << ret;
	return 0;
}