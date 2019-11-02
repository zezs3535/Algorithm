#include <iostream>
using namespace std;

int card[10002];
int dp[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
		dp[i] = card[i];
	}
	if (N == 1) {
		cout << card[N];
		return 0;
	}
	else {
		for (int i = 1; i <= N; i++) {

		}
	}
	return 0;
}