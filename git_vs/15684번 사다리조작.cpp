#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> emptyPos;
int n, m, h;
int answer = -1;

bool check(vector<vector<int>>& arr) {
	for (int i = 1; i <= m; i++) {
		pii cur = { 1,i }; //��ٸ��� �� ������ ����
		int start = i;
		while (cur.first != (n + 1)) {
			if (arr[cur.first][cur.second] == 1)cur.second += 1; //���������� ����������� ���������� ��ĭ
			else if (arr[cur.first][cur.second] == -1)cur.second -= 1; //�������� ����������� �������� ��ĭ
			cur.first++;
		}
		if (start != cur.second)return false;
	}
	return true;
}

void search(vector<vector<int>>& arr) {
	if (check(arr)) {
		answer = 0;
		return;
	}
	for (int i = 0; i < emptyPos.size(); i++) {
		if (arr[emptyPos[i].first][emptyPos[i].second] == 0 && arr[emptyPos[i].first][emptyPos[i].second + 1] == 0) {
			arr[emptyPos[i].first][emptyPos[i].second] = 1;
			arr[emptyPos[i].first][emptyPos[i].second + 1] = -1;
			if (check(arr)) {
				/*answer = 1;
				return;*/
				if (answer == -1 || answer > 1)answer = 1;
			}
			for (int j = i + 1; j < emptyPos.size(); j++) {
				if (arr[emptyPos[j].first][emptyPos[j].second] == 0 && arr[emptyPos[j].first][emptyPos[j].second + 1] == 0) {
					arr[emptyPos[j].first][emptyPos[j].second] = 1;
					arr[emptyPos[j].first][emptyPos[j].second + 1] = -1;
					if (check(arr)) {
						/*answer = 2;
						return;*/
						if (answer == -1 || answer > 2)answer = 2;
					}
					for (int k = j + 1; k < emptyPos.size(); k++) {
						if (arr[emptyPos[k].first][emptyPos[k].second] == 0 && arr[emptyPos[k].first][emptyPos[k].second + 1] == 0) {
							arr[emptyPos[k].first][emptyPos[k].second] = 1;
							arr[emptyPos[k].first][emptyPos[k].second + 1] = -1;
							if (check(arr)) {
								/*answer = 3;
								return;*/
								if (answer == -1 || answer > 3)answer = 3;
							}
							arr[emptyPos[k].first][emptyPos[k].second] = 0;
							arr[emptyPos[k].first][emptyPos[k].second + 1] = 0;
						}
					}
					arr[emptyPos[j].first][emptyPos[j].second] = 0;
					arr[emptyPos[j].first][emptyPos[j].second + 1] = 0;
				}
			}
			arr[emptyPos[i].first][emptyPos[i].second] = 0;
			arr[emptyPos[i].first][emptyPos[i].second + 1] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> h >> n; //������ �ٲ㼭 �Է¹޴´�
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < h; i++) {
		int q, w; cin >> q >> w; //q�� q+1 ���μ��� w�� ���� ��ġ���� ����
		arr[q][w] = 1;
		arr[q][w + 1] = -1; //���������� ������� 1, �������� ������� -1
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == 0)emptyPos.push_back({ i,j });
		}
	}
	search(arr);
	cout << answer;
	return 0;
}