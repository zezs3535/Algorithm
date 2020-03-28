#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;

int bfs(vector<vector<int>> &picture, vector<vector<int>> &visit, int start, int i, int j, int m, int n) {
	q.push({ i,j }); visit[i][j] = 1;
	int size = 0;
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		size++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny >= 0 && nx >= 0 && ny < m&&nx < n&&visit[ny][nx] == 0 && picture[ny][nx] == start) {
				q.push({ ny,nx });
				visit[ny][nx] = 1;
			}
		}
	}
	return size;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<vector<int>>visit(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] > 0 && visit[i][j] == 0) {
				int size = bfs(picture, visit, picture[i][j], i, j, m, n);
				if (max_size_of_one_area < size)max_size_of_one_area = size;
				number_of_area++;
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}