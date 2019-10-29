#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int bug = 0;
		int map[51][51];
		queue<pair<int, int>> q;
		pair<int, int> x; //배추의 좌표
		memset(map, -1, sizeof(map)); //배열을 -1로 초기화
		int G, S, N;
		cin >> G >> S >> N;
		for (int i = 0; i < N; i++) { //x,y값을 입력받고 map[y][x]에 대입
			cin >> x.first >> x.second;
			map[x.second][x.first] = 1;
		}
		/*도착점이 -1이 아닐때 큐에넣고 pop하면서
		그 지점을 -1로 변경 하고 주변 탐색,
		주변을 돌다가 -1이 아닌 값을 발견하면 큐에 넣는다*/
		for (int i = 0; i < S; i++) { //2차원배열 루프
			for (int j = 0; j < G; j++) {
				int cx = 0;
				int cy = 0;
				if (map[i][j] == 1) {
					q.push(make_pair(i, j));
					map[i][j] = -1;
					bug++;
				}
				while (!q.empty()) {
					cx = q.front().second;
					cy = q.front().first;
					q.pop();
					for (int k = 0; k < 4; k++) {
						if ((cy + dy[k]) < 0 || (cy + dy[k]) >= S || (cx + dx[k]) < 0 || (cx + dx[k]) >= G)
							continue;
						if (map[cy + dy[k]][cx + dx[k]] == 1) {
							q.push(make_pair(cy + dy[k], cx + dx[k]));
							map[cy + dy[k]][cx + dx[k]] = -1;
						}
					}
				}
			}
		}
		cout << bug<<"\n";
	}
	return 0;
}
