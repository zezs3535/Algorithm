#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

struct process {
	int a;
	int b;
	int c;
};

struct cmp {
	bool operator()(process pa, process pb) {
		if (pa.c == pb.c) return pa.a > pb.a;
		return pa.c < pb.c;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	priority_queue<process, vector<process>, cmp> pq;
	for (int i = 0; i < m; i++) {
		process tmp; cin >> tmp.a >> tmp.b >> tmp.c;
		pq.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		if (pq.empty())break;
		process tmp = pq.top(); pq.pop();
		tmp.b--;
		tmp.c--;
		if(tmp.b!=0)pq.push(tmp);
		cout << tmp.a << "\n";
	}
	return 0;
}