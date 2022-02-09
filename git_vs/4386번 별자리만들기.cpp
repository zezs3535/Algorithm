#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
vector<pdd> arr;
double getDis(int cur, int nxt) {
	return sqrt(pow(arr[cur].first-arr[nxt].first,2)+pow(arr[cur].second-arr[nxt].second,2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(2);
	int t; cin >> t;
	arr.assign(t, pdd());
	for (int i = 0; i < t; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	vector<bool> v(t, false);
	double ans = 0.0;
	priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
	pq.push({ 0.0 , 0 });
	while (!pq.empty()) {
		int cur = pq.top().second;
		double curdis = pq.top().first;
		pq.pop();
		if (v[cur])continue;
		v[cur] = true;
		ans += curdis;
		for (int i = 0; i < t; i++) {
			if (v[i])continue;
			pq.push({ getDis(cur,i),i });
		}
	}
	cout << ans;
	return 0;
}
