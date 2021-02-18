#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
typedef pair<int, int> pii;
int n, m, d;
int enemyPos[16][16];

bool isNotEnemy(vector<vector<int>>& enemy) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (enemy[i][j])return true;
		}
	}
	return false;
}

int killEnemy(vector<pii>& archor, vector<vector<int>>& enemy) {
	int killCnt = 0;
	set<pii> killedEnemyList;
	for (int k = 0; k < 3; k++) {
		int minDis = MAX;
		pii killedEnemy;
		bool flag = false;
		for (int j = m - 1; j >= 0; j--) { //������ �Ʒ����� Ž��
			for (int i = n - 1; i >= 0; i--) { //��������
				if (enemy[i][j]) { //���� �ִ�
					int killDis = abs(archor[k].first - i) + abs(archor[k].second - j);
					if (killDis > d)continue;
					if (minDis >= killDis) { //���ʳ�����
						minDis = killDis;
						killedEnemy = { i,j };
						flag = true;
					}
				}
			}
		}
		if(flag)killedEnemyList.insert(killedEnemy); //�� ������ ����Ʈ�� �־�� (�ٷ� �����ϸ� �ȵǴϱ�)
	}
	for (auto iter = killedEnemyList.begin(); iter != killedEnemyList.end(); iter++) {
		pii cur = *iter;
		enemy[cur.first][cur.second] = 0;
		//cout << cur.first << " " << cur.second << "\n";
		killCnt++;
	}
	return killCnt;
}

void moveDownEnemy(vector<vector<int>>& enemy) {
	for (int i = n - 1; i >= 0; i--) { //������ �Ʒ����� Ž��
		for (int j = m - 1; j >= 0; j--) { //��������
			if (enemy[i][j]) { //���� �ִ�
				if (i + 1 == n) {
					enemy[i][j] = 0;
				}
				else {
					enemy[i + 1][j] = 1;
					enemy[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int answer = 0;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> enemyPos[i][j];
		}
	}
	vector<int> archorPos(m, 0);
	fill(archorPos.end() - 3, archorPos.end(), 1); //���� ��ó�� ���� ����
	do {
		int kill = 0;
		vector<pii> archor;
		vector<vector<int>> enemy(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				enemy[i][j] = enemyPos[i][j];
			}
		}
		for (int i = 0; i < m; i++)if (archorPos[i])archor.push_back({ n,i }); //archorPos �迭�� ���� archorť�� ����
		while (isNotEnemy(enemy)) { //���� ������ break
			kill += killEnemy(archor, enemy);
			moveDownEnemy(enemy);
		}
		answer = max(kill, answer);
	} while (next_permutation(archorPos.begin(), archorPos.end())); //archorPos �迭�� ���� �����鼭 �ü� ��ġ ����
	cout << answer;
	return 0;
}