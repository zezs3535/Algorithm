#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int maxret = 0;
	int minret = 1000000;
	int n; cin >> n;
	int q, w, e;
	cin >> q >> w >> e;
	int maxsum[3] = { 0, };
	int minsum[3] = { 0, };
	int maxtmp[3];
	int mintmp[3];
	maxsum[0] = q;
	minsum[0] = q;
	maxsum[1] = w;
	minsum[1] = w;
	maxsum[2] = e;
	minsum[2] = e;

	for (int i = 1; i < n; i++) {
		cin >> q >> w >> e;
		for (int j = 0; j < 3; j++) {
			maxtmp[j] = maxsum[j];
			mintmp[j] = minsum[j];
		}
		maxtmp[0] = max(maxsum[0] + q, maxsum[1] + q);
		maxtmp[1] = max(maxsum[0] + w, max(maxsum[1] + w, maxsum[2] + w));
		maxtmp[2] = max(maxsum[1] + e, maxsum[2] + e);
		mintmp[0] = min(minsum[0] + q, minsum[1] + q);
		mintmp[1] = min(minsum[0] + w, min(minsum[1] + w, minsum[2] + w));
		mintmp[2] = min(minsum[1] + e, minsum[2] + e);
		for (int j = 0; j < 3; j++) {
			maxsum[j] = maxtmp[j];
			minsum[j] = mintmp[j];
		}
	}
	for (int i = 0; i < 3; i++) {
		maxret = max(maxret, maxsum[i]);
		minret = min(minret, minsum[i]);
	}
	cout << maxret << " " << minret;
	return 0;
}