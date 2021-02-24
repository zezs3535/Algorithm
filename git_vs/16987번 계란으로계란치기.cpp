#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 0;
struct Egg {
	int dur;
	int w;
};

void search(vector<Egg>& egg, int idx) {
	if (idx == n) { //집은게 맨 오른쪽 계란이면
		int cnt = 0;
		for (int i = 0; i < n; i++)if (egg[i].dur <= 0)cnt++;
		answer = max(answer, cnt);
		return;
	}
	if (egg[idx].dur <= 0) {
		search(egg, idx + 1); //손에 든 계란이 깨져있으면
		return;
	}
	for (int pick = 0; pick < n; pick++) {
		if (idx == pick)continue;
		if (egg[pick].dur > 0) { //내구도가 있으면
			egg[idx].dur -= egg[pick].w;
			egg[pick].dur -= egg[idx].w;
			search(egg, idx + 1);
			egg[idx].dur += egg[pick].w;
			egg[pick].dur += egg[idx].w;
		}
		else { //때리려고 했는데 깨진 계란이면?
			search(egg, idx + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<Egg> egg(n);
	for (int i = 0; i < n; i++) {
		int d, we; cin >> d >> we;
		egg[i].dur = d;
		egg[i].w = we;
	}
	search(egg, 0);
	cout << answer;
	return 0;
}