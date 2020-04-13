#include <bits/stdc++.h>

using namespace std;

int wmap[8][8] = { //øﬁ¬ ¿ß∞° w¿Œ ∏ 
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1}
};
int bmap[8][8] = { //øﬁ¬ ¿ß∞° b¿Œ ∏ 
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0}
};

int check(vector<vector<int> >& map, int n, int m) {
	int wcnt = 0;
	int bcnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i + n][j + m] != wmap[i][j])wcnt++;
			if (map[i + n][j + m] != bmap[i][j])bcnt++;
		}
	}
	return min(wcnt, bcnt);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	char temp;
	int answer = 64;
	cin >> n >> m;
	vector<vector<int> >map(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			temp == 'W' ? map[i][j] = 1 : map[i][j]=0 ; //w=1, b=0
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			answer = min(answer, check(map, i, j));
		}
	}
	cout << answer;
	return 0;
}