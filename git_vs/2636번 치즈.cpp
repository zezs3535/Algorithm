#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int melt = 0;

bool canMelt(vector<vector<int>>& arr) { //�� ������ �ִ��� Ȯ���Ѵ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0)return true;
		}
	}
	return false;
}

bool bfs(vector<vector<int>>& arr, int y, int x) { //Ž��
	if (!canMelt(arr))return false; //�� ������ ������ return false
	vector<vector<bool>> v(n, vector<bool>(m, false));
	queue<pii> q;
	q.push({ y,x });
	v[y][x] = true;
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || v[ny][nx])continue;
			if (arr[ny][nx] == 0) { //ǥ�� Ž���� ���� ���� Ž��
				v[ny][nx] = true;
				q.push({ ny,nx });
			}
			if (arr[ny][nx] == 1) { //�Ѻκ��� ���ٰ� ġ� ������(ǥ���� ������)
				arr[ny][nx] = 2; //����� �κ��� 2�� �ٲ���
			}
		}
	}

	melt = 0;
	for (int i = 0; i < n; i++) { //�� ǥ���� üũ�� ���� 2�� 0���� �ٲ��ָ� ġ� ��°����� ó��
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 0;
				melt++;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int t = 0;

	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		if (!bfs(arr, 0, 0))break;
		t++;
	}
	cout << t << "\n" << melt;
	return 0;
}