#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int k; cin >> k;
	int l;
	int answer = 0;
	int dir = 0;
	bool flag = true;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	deque<pii> snake; //��
	arr[0][0] = 1; //���� ���׾Ƹ� (����?)
	snake.push_back({ 0,0 });
	for (int i = 0; i < k; i++) { //��� ��ġ
		int q, w; cin >> q >> w;
		arr[q - 1][w - 1] = -1; //���
	}
	cin >> l;
	queue<pair<int, char>> ins;
	for (int i = 0; i < l; i++) {
		int q;
		char w;
		cin >> q >> w;
		ins.push({ q,w });
	}
	while (flag) {
		answer++;
		int ny = snake.back().first + dy[dir];
		int nx = snake.back().second + dx[dir];
		if (ny >= n || ny < 0 || nx >= n || nx < 0 || arr[ny][nx]==1) { //���� �ε����� ��
			flag = false;
			break;
		}
		snake.push_back({ ny,nx }); //�Ⱥε����� �ϴ� ��ĭ ��
		if (arr[ny][nx] == -1) { //����̸� �Ӹ��� �þ
			arr[ny][nx] = 0;
		}
		else {
			arr[ny][nx] = 1;
			pii tail = snake.front();
			arr[tail.first][tail.second] = 0;
			snake.pop_front();
		}
		if (ins.size() > 0 && ins.front().first == answer) {
			if (ins.front().second == 'D')dir = (dir + 1) % 4;
			else {
				dir = dir - 1;
				if (dir == -1)dir = 3;
			}
			ins.pop();
		}
	}
	cout << answer;
	return 0;
}