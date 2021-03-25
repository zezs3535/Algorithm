#include <bits/stdc++.h>

using namespace std;
#define INF 2147483647
typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
struct pos {
	int w;
	int y;
	int x;
};
struct cmp {
	bool operator()(const pos& a, const pos& b) {
		return a.w > b.w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while (1) {
		int n; cin >> n;
		if (n == 0)break;
		vector<vector<int>> arr(n, vector<int>(n, 0));
		vector<vector<int>> dis(n, vector<int>(n, 0));
		priority_queue<pos, vector<pos>, cmp> pq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				dis[i][j] = INF;
			}
		}
		dis[0][0] = arr[0][0];
		pq.push({ arr[0][0],0,0 });
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			int cy = cur.y;
			int cx = cur.x;
			int cw = cur.w;
			for (int idx = 0; idx < 4; idx++) {
				int ny = cy + dy[idx];
				int nx = cx + dx[idx];
				if (ny >= n || ny < 0 || nx >= n || nx < 0)continue;
				if (dis[ny][nx] > cw + arr[ny][nx]) {
					dis[ny][nx] = cw + arr[ny][nx];
					pq.push({ dis[ny][nx],ny,nx });
				}
			}
		}
		cout << "Problem " << cnt << ": " << dis[n - 1][n - 1] << "\n";
		arr.clear();
		dis.clear();
		cnt++;
	}
	return 0;
}