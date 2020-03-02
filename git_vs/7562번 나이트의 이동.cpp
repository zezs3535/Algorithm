#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int l;
		cin >> l;
		vector<vector<int> >map(l, vector<int>(l, 0));
		queue<pii> q;
		pii start;
		pii end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		q.push(start);
		if (start == end) {
			cout << "0\n";
			continue;
		}
		while (!q.empty()) { //도착지점이 1일때
			if (map[end.first][end.second])break;
			pii cur = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];
				if (ny<0 || ny> l - 1 || nx<0 || nx> l - 1)continue;
				if (map[ny][nx])continue;
				q.push({ ny,nx });
				map[ny][nx] = map[cur.first][cur.second] + 1;
			}
		}
		cout << map[end.first][end.second]<<"\n";
	}
	return 0;
}