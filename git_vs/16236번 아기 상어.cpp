#include <bits/stdc++.h>

using namespace std;
struct fish {
	int y;
	int x;
	int dis;
};
typedef pair<int, int> pii;
int n;
int arr[21][21];
int ret = 0;
int sharkSize = 2;
int feed = 0;
vector<fish> fishPos;
pii sharkPos;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool cmp(fish& a, fish& b) {
	int y1 = abs(a.y - sharkPos.first);
	int x1 = abs(a.x - sharkPos.second);
	int y2 = abs(b.y - sharkPos.first);
	int x2 = abs(b.x - sharkPos.second);
	if (a.dis==b.dis) {
		if (a.y == b.y)return a.x < b.x;
		return a.y < b.y;
	}
	return a.dis < b.dis;
}

void canEatFish() {
	int cnt = 0;
	vector<vector<int>> visit(n, vector<int>(n, 0));
	vector<vector<int>> distance(n, vector<int>(n, 0));
	queue<pii> q;
	q.push({ sharkPos.first,sharkPos.second });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		visit[cur.first][cur.second]=1;
		cnt++;
		for (int idx = 0; idx < 4; idx++) {
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny >= n || nx >= n || ny < 0 || nx < 0 || visit[ny][nx]==1)continue;
			if (arr[ny][nx] > sharkSize)continue;
			if (arr[ny][nx] != 0 && arr[ny][nx]<sharkSize) {
				fishPos.push_back({ ny,nx,distance[cur.first][cur.second]+1 });
			}
			q.push({ ny,nx });
			visit[ny][nx] = 1;
			distance[ny][nx] = distance[cur.first][cur.second] + 1;
		}
	}
}

void eatFish() {
	while (true) {
		if (fishPos.empty())break;
		sort(fishPos.begin(), fishPos.end(), cmp);
		ret += fishPos[0].dis;
		feed++;
		arr[sharkPos.first][sharkPos.second] = 0;
		arr[fishPos[0].y][fishPos[0].x] = 0;
		sharkPos.first = fishPos[0].y;
		sharkPos.second = fishPos[0].x;
		if (sharkSize == feed) {
			feed = 0;
			sharkSize++;
		}
		fishPos.clear();
		canEatFish();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sharkPos.first = i;
				sharkPos.second = j;
			}
		}
	}
	canEatFish();
	eatFish();
	cout << ret;
	return 0;
}