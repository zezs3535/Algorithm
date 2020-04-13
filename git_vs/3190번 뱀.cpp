#include <bits/stdc++.h>
#define pii pair<int, int>
#define pic pair<int, char>
using namespace std;

pii dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
pii tail = { 0,0 };
deque<pic> ins;
deque<pii> snake;
int direction = 0;
int answer = 0;
int n = 0;
int cnt = 0;
bool flag = true;
int run(vector<vector<int>>& map, vector<vector<int>>& visit) {
	while(1){
		answer++;
		int nx = snake.front().second + dir[direction % 4].second;
		int ny = snake.front().first + dir[direction % 4].first;
		if (nx >= n || nx < 0 || ny< 0 || ny >= n || visit[ny][nx] == 1) {
			return answer;
		}
		snake.push_front({ ny,nx });
		visit[ny][nx] = 1;
		if (map[ny][nx] == 1) { //사과가 있을 때
			map[ny][nx] = 0;
		}
		else {
			tail = snake.back();
			visit[tail.first][tail.second] = 0;
			snake.pop_back();
		}
		if (ins.size() && ins.front().first == answer) {
			if (ins.front().second == 'D')direction++;
			else if (ins.front().second == 'L')direction += 3;
			ins.pop_front();
		}
	}
	
	return answer;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	deque<int> a;
	int apple;
	cin >> n >> apple;
	vector<vector<int> >map(n, vector<int>(n, 0)); //사과 1
	vector<vector<int> >visit(n, vector<int>(n, 0));
	visit[0][0] = 1;
	snake.push_back({ 0,0 });
	for (int i = 0; i < apple; i++) {
		int x, y;
		cin >> y >> x;
		map[y-1][x-1] = 1;
	}

	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp1;
		char tmp2;
		cin >> tmp1 >> tmp2;
		ins.push_back({ tmp1,tmp2 });
	}
	cout<<run(map, visit);
	return 0;
}