#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dx[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
int dy[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	pii js;
	vector<pii> arduino;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'R') {
				arr[i][j] = 1; //�Ƶ��̳�
				arduino.push_back({ i,j });
			}
			else if (tmp == 'I') {
				js.first = i;
				js.second = j;
			}
		}
	}
	string ins; cin >> ins;
	for (int i = 0; i < ins.size(); i++) {
		
		//���� �̵�
		js.first += dy[ins[i]-'0'];
		js.second += dx[ins[i]-'0'];
		

		//�̵��� ĭ�� �Ƶ��̳� ������ ��
		if (arr[js.first][js.second] > 0) {
			cout << "kraj "<<(i+1);
			return 0;
		}
		//�Ƶ��̳� �̵�
		for (int j = 0; j < arduino.size(); j++) {
			int minDis = 999;
			int minDir = 0;
			//�ּ� �Ÿ� ���ؼ� ��ĭ ����
			for (int dir = 1; dir <= 9; dir++) {
				if (dir == 5)continue;
				int ny = arduino[j].first + dy[dir];
				int nx = arduino[j].second + dx[dir];
				if (ny > n || nx > m || ny < 0 || nx < 0)continue;
				//�Ƶ��̳밡 �������µ� ������ ������ ��
				if (ny == js.first && nx == js.second) {
					cout << "kraj " << (i + 1);
					return 0;
				}
				int getDis = abs(js.first - ny) + abs(js.second - nx);
				if (minDis >= getDis) {
					minDis = getDis;
					minDir = dir;
				}
			}
			arr[arduino[j].first][arduino[j].second]--;
			arr[arduino[j].first+dy[minDir]][arduino[j].second+dx[minDir]]++;
		}
		arduino.clear();
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (arr[y][x] > 1)arr[y][x] = 0;
				if (arr[y][x] == 1)arduino.push_back({ y,x });
			}
		}
	}
	arr[js.first][js.second] = 9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)cout << ".";
			else if (arr[i][j] == 1)cout << "R";
			else if (arr[i][j] == 9)cout << "I";
		}
		cout << "\n";
	}
	return 0;
}