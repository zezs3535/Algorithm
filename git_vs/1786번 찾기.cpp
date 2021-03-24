#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
vector<int> getPi(string& p) {
	vector<int> pi(m, 0);
	int j = 0;
	for (int i = 1; i < m; i++) { //pi의 처음은 0이니까 1부터 시작
		while (j > 0 && p[i] != p[j])j = pi[j - 1];
		if (p[i] == p[j])pi[i] = ++j;
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string t; getline(cin, t);
	string p; getline(cin, p);
	n = t.size();
	m = p.size();

	vector<int> pi(m,0);
	vector<int> ans;
	pi = getPi(p); //실패함수 pi 생성

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && t[i] != p[j])j = pi[j - 1];
		if (t[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)cout << ans[i]<<" ";
	return 0;
}