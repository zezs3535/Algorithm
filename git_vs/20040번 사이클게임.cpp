
#include <bits/stdc++.h>

using namespace std;
vector<int> p;

int f(int a) {
	if (p[a] == a) return a;
	return p[a] = f(p[a]);
}

void u(int a, int b) {
	if (f(a)==f(b))return;
	p[f(b)] = f(a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	p.assign(n, int());
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (f(a) == f(b)) {
			cout << i + 1;
			return 0;
		}
		u(a, b);
	}
	cout << 0;
	return 0;
}