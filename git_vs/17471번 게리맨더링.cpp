#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

typedef pair<int, int> pii;
int n;
int city[11] = { 0, };
vector<int> adj[11];
int answer = MAX;

void election(vector<bool>& v) {
	queue<int> q1;
	queue<int> q2;
	bool group1[11] = { false, };
	bool group2[11] = { false, };
	bool visitgroup1[11] = { false, };
	bool visitgroup2[11] = { false, };
	int sum1 = 0;
	int sum2 = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) { //v[i]가 0이면 1선거구 아니면 2선거구
		if (!v[i])group1[i] = true;
		else {
			group2[i] = true;
			cnt++;
		}
	}
	if (cnt == n || cnt == 0)return; //선거구가 하나만 나올때
	for (int i = 1; i <= n; i++) {
		if (group1[i] == 0)continue; //1번 선거구가 아니면 넘어감
		q1.push(i);
		visitgroup1[i] = true;
		while (!q1.empty()) {
			int idx = q1.front(); q1.pop();
			sum1 += city[idx];
			for (int j = 0; j < adj[idx].size(); j++) {
				int cur = adj[idx][j];
				if (group1[cur] == 0 || visitgroup1[cur] == 1)continue;
				q1.push(cur);
				visitgroup1[cur] = true;
			}
		}
		break;
	}
	for (int i = 1; i <= n; i++) {
		if (group2[i] == 0)continue; //1번 선거구가 아니면 넘어감
		q2.push(i);
		visitgroup2[i] = true;
		while (!q2.empty()) {
			int idx = q2.front(); q2.pop();
			sum2 += city[idx];
			for (int j = 0; j < adj[idx].size(); j++) {
				int cur = adj[idx][j];
				if (group2[cur] == 0 || visitgroup2[cur] == 1)continue;
				q2.push(cur);
				visitgroup2[cur] = true;
			}
		}
		break;
	}
	for (int i = 1; i <= n; i++) {
		if (group1[i] != visitgroup1[i] || group2[i] != visitgroup2[i])return;
	}
	answer = min(answer, abs(sum1 - sum2));
}

void comb(vector<bool>& v, int pick) {
	if (pick == n) {
		election(v);
		return;
	}
	v[pick] = true;
	comb(v, pick + 1);
	v[pick] = false;
	comb(v, pick + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> city[i];
	vector<bool> v(n + 1,false);
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int adjCity; cin >> adjCity;
			adj[i].push_back(adjCity);
		}
	}
	comb(v, 0);
	if (answer == MAX)answer = -1;
	cout << answer;
	return 0;
}