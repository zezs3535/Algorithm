//comment only english

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int max=1;
	int cnt = 1;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N-1; i++) {
		if (arr[i + 1] >= arr[i])
			cnt++;
		else
			cnt = 1;
		if (cnt >= max)
			max = cnt;
	}
	cout << max;
	return 0;
}