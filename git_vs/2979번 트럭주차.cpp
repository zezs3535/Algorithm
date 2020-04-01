#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cost[4];
	cost[0] = 0;
	for (int i = 1; i <= 3; i++) {
		int tmp;
		cin >> tmp;
		cost[i] = tmp * i;
	}
	int starttime, endtime;
	int num[101] = { 0, };
	int answer = 0;
	for (int i = 0; i < 3; i++) {
		cin >> starttime >> endtime;
		for (int j = starttime; j < endtime; j++) {
			num[j] += 1;
		}
	}
	for (int i = 1; i <= 100; i++) {
		answer += cost[num[i]];
	}
	cout << answer;
	return 0;
}