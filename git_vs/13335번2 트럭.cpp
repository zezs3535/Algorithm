#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, bridgeWeight; cin >> n >> w >> bridgeWeight;
	vector<int> truck(n);
	queue<int> bridge;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	int truckSumWeight = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			answer++;
			if (bridge.size() == w) {
				truckSumWeight -= bridge.front();
				bridge.pop();
			}
			if (truckSumWeight+truck[i]<=bridgeWeight) {
				bridge.push(truck[i]);
				truckSumWeight += truck[i];
				break;
			}
			else {
				bridge.push(0);
			}
		}
	}
	cout << answer+w;
	return 0;
}