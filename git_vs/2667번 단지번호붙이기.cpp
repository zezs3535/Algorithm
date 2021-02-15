#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int arr[26][26];
bool visit[26][26];
int n;
int bfs(int i, int j) {
	int cnt = 1;
	queue<pii> q;
	q.push({ i,j });
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= n || nx >= n || ny < 0 || nx < 0)continue;
			if (visit[ny][nx])continue;
			if (!arr[ny][nx])continue;
			visit[ny][nx] = true;
			q.push({ ny,nx });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int cnt = 0;
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(arr[i][j]==1 && !visit[i][j]){
				cnt++;
				visit[i][j] = true;
				answer.push_back(bfs(i, j));
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << cnt << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}