#include <bits/stdc++.h>

using namespace std;

struct Color {
	int r;
	int g;
	int b;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<Color> arr(n);
	vector<Color> r(n);
	vector<Color> g(n);
	vector<Color> b(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].r >> arr[i].g >> arr[i].b;
	}
	r[0].r = arr[0].r; //start
	g[0].g = arr[0].g;
	b[0].b = arr[0].b;
	r[0].g = r[0].b = 1001;
	g[0].r = g[0].b = 1001;
	b[0].r = b[0].g = 1001;
	for (int i = 1; i < n; i++) {
		r[i].r = min(r[i - 1].g, r[i - 1].b) + arr[i].r;
		r[i].g = min(r[i - 1].r, r[i - 1].b) + arr[i].g;
		r[i].b = min(r[i - 1].r, r[i - 1].g) + arr[i].b;
		g[i].r = min(g[i - 1].g, g[i - 1].b) + arr[i].r;
		g[i].g = min(g[i - 1].r, g[i - 1].b) + arr[i].g;
		g[i].b = min(g[i - 1].r, g[i - 1].g) + arr[i].b;
		b[i].r = min(b[i - 1].g, b[i - 1].b) + arr[i].r;
		b[i].g = min(b[i - 1].r, b[i - 1].b) + arr[i].g;
		b[i].b = min(b[i - 1].r, b[i - 1].g) + arr[i].b;
	}
	int ans = min(r[n - 1].g, r[n - 1].b);
	ans = min(ans, min(g[n - 1].r, g[n - 1].b));
	ans = min(ans, min(b[n - 1].r, b[n - 1].g));
	cout << ans;
	return 0;
}