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
		for (int j = m - 1; j >= 0; j--) { //오른쪽 아래부터 탐색
			for (int i = n - 1; i >= 0; i--) { //왼쪽으로
				if (enemy[i][j]) { //적이 있다
					int killDis = abs(archor[k].first - i) + abs(archor[k].second - j);
					if (killDis > d)continue;
					if (minDis >= killDis) { //왼쪽놈으로
						minDis = killDis;
						killedEnemy = { i,j };
						flag = true;
					}
				}
			}
		}
		if(flag)killedEnemyList.insert(killedEnemy); //적 제거할 리스트에 넣어둠 (바로 제거하면 안되니까)
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
	for (int i = n - 1; i >= 0; i--) { //오른쪽 아래부터 탐색
		for (int j = m - 1; j >= 0; j--) { //왼쪽으로
			if (enemy[i][j]) { //적이 있다
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
	fill(archorPos.end() - 3, archorPos.end(), 1); //성에 아처를 놓는 조합
	do {
		int kill = 0;
		vector<pii> archor;
		vector<vector<int>> enemy(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				enemy[i][j] = enemyPos[i][j];
			}
		}
		for (int i = 0; i < m; i++)if (archorPos[i])archor.push_back({ n,i }); //archorPos 배열의 값을 archor큐에 저장
		while (isNotEnemy(enemy)) { //적이 없으면 break
			kill += killEnemy(archor, enemy);
			moveDownEnemy(enemy);
		}
		answer = max(kill, answer);
	} while (next_permutation(archorPos.begin(), archorPos.end())); //archorPos 배열로 조합 돌리면서 궁수 위치 조절
	cout << answer;
	return 0;
}