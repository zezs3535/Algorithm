#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, bridgeLen, bridgeWeight;
	cin >> n >> bridgeLen >> bridgeWeight;
	vector<int> truck(n);
	queue<int> bridge;
	int check = n;
	int time = 0; //�ð�
	int weightSum = 0; //�ٸ��� Ʈ�� ������ ��
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	for (int i = 0; i < n; i++) {
		while (1) {
			time++;
			if (bridge.size() == bridgeLen) {
				weightSum -= bridge.front();
				bridge.pop();
			}
			if (weightSum + truck[i] > bridgeWeight)bridge.push(0);
			else {
				bridge.push(truck[i]);
				weightSum += truck[i];
				break;
			}
		}
	}
	cout << time+bridgeLen;
	return 0;
}