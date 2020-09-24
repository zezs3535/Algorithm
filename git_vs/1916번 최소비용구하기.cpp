#include <bits/stdc++.h>
#define MAX 1000000002
#define pii pair<int,int>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	cin >> n >> m;
	vector<int> city(1001, MAX);
	vector<pii> bus[100001];
	for (int i = 0; i < m; i++) {
		int idx = 0;
		cin >> idx;
		int des, dis; cin >> des >> dis;
		bus[idx].push_back({ dis,des });
	}
	int startCity, desCity;
	cin >> startCity >> desCity;
	city[startCity] = 0;
	pq.push({ 0,startCity });
	while (!pq.empty()) {
		int distance = pq.top().first;
		int target = pq.top().second;
		pq.pop();
		if (city[target] != distance) continue;
		else {
			for (auto nxt : bus[target]) {
				//cout << nxt.first <<" "<< nxt.second << "\n";//target에서 출발하는 버스가 있고, 배열에 쓰여진 값보다 더 짧으면? 테이블 수정 후 힙에 삽입
				if (city[nxt.second] > nxt.first+distance) {
					city[nxt.second] = nxt.first+distance;
					pq.push({ city[nxt.second], nxt.second });
				}
			}
		}
	}
	cout << city[desCity];
	return 0;
}