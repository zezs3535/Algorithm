#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001] = { 0, };
int N, C;

bool check(int N) {

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int L = 1;
	int R = max(arr[0], arr[N - 1]);
	int mid = (L + R) / 2;

	return 0;
}