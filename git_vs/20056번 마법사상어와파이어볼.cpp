#include <bits/stdc++.h>

using namespace std;
//�迭�� m,s,d,cnt
//���̾�� m,s,d
//�̵��ϸ鼭 queue���� pop�ϸ鼭 �迭�� üũ
//2���̻��̸� ������, �ƴϸ� �׳� �ΰ�
//�迭�� �ִ� ���� queue�� �� �����鼭 �迭 �ʱ�ȭ
//�������°� cnt�� 2�̻����� üũ�ϰ�
//������ ��� Ȧ��or¦���� Ȧ���� 1���ϰ� ¦���� -1���ؼ�
//cnt�� �迭��d���̶� ������ �ٸ��� üũ
typedef pair<int, int> pii;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int n, m, k;
struct fireBall {
	int r;
	int c;
	int m;
	int s;
	int d;
};
struct Info {
	int m;
	int s;
	int d;
	int cnt = 0;
	vector<int> dir;
};


queue<fireBall> fb;

void move(vector<vector<Info>>& arr) {
	while (!fb.empty()) {
		fireBall cur = fb.front();
		fb.pop();
		int ny = cur.r + dy[cur.d] * cur.s;
		int nx = cur.c + dx[cur.d] * cur.s;

		//�迭 ������ �����°� üũ�ϱ� ���� ��ⷯ ����
		if (ny >= n)ny = ny % n;
		else if (ny < 0)ny = (ny % n) + n;
		if (nx >= n)nx = nx % n;
		else if (nx < 0)nx = (nx % n) + n;
		if (ny == n)ny = 0;
		if (nx == n)nx = 0;
		//�迭�� ���� ���̾�� ������ ��´�
		arr[ny][nx].m += cur.m;
		arr[ny][nx].s += cur.s;
		arr[ny][nx].d += cur.d % 2 == 0 ? -1 : 1; //¦���� -1, Ȧ���� 1 ���ϱ�
		arr[ny][nx].dir.push_back(cur.d);
		arr[ny][nx].cnt += 1; //��ġ���� üũ�� ���� ���ϱ�
	}
}

void isDuplicated(vector<vector<Info>>& arr) {
	queue<Info> cur;
	queue<pii> curPos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Info tmp = arr[i][j];
			if (arr[i][j].cnt > 1) { //��ġ�°� ������ �ְ�
				cur.push({ tmp.m, tmp.s, tmp.d, tmp.cnt }); //��ġ�°��� queue�� ��� ����
				curPos.push({ i,j });
			}
			else if (arr[i][j].cnt == 1) { //�ϳ��� ������ ���� �ְ�
				fb.push({ i,j,tmp.m,tmp.s,tmp.dir[0] }); //���̾�� r,c,m,s,d ����
			}
		}
	}

	while (!cur.empty()) { //������ ���̾�� ������ �۾�
		Info tmp = cur.front(); //�迭�� ������ ���� tmp����
		pii tmpPos = curPos.front();
		cur.pop();
		curPos.pop();
		int divM = tmp.m / 5; //������ ������ �� / 5
		if (divM == 0)continue; //������ 0�̸� �׳� �ѱ��
		int divS = tmp.s / tmp.cnt; //�ӷ��� �ӷ��� �� / ������ ����
		if (tmp.d == tmp.cnt || (tmp.d * -1) == tmp.cnt) { //������ ��� Ȧ/¦���϶�
			for (int idx = 0; idx < 8; idx++) {
				if (idx % 2 == 0) {
					/*int ny = tmpPos.first + dy[idx] * divS;
					int nx = tmpPos.second + dx[idx] * divS;
					if (ny >= n)ny = ny % n;
					else if (ny < 0)ny = (ny % n) + n;
					if (nx >= n)nx = nx % n;
					else if (nx < 0)nx = (nx % n) + n;
					fb.push({ ny,nx,divM,divS,idx });*/
					fb.push({ tmpPos.first,tmpPos.second,divM,divS,idx });
				}
			}
		}
		else { //�ƴҶ�
			for (int idx = 0; idx < 8; idx++) {
				if (idx % 2 == 1) {
					/*int ny = tmpPos.first + dy[idx] * divS;
					int nx = tmpPos.second + dx[idx] * divS;
					if (ny >= n)ny = ny % n;
					else if (ny < 0)ny = (ny % n) + n;
					if (nx >= n)nx = nx % n;
					else if (nx < 0)nx = (nx % n) + n;
					fb.push({ ny,nx,divM,divS,idx });*/
					fb.push({ tmpPos.first,tmpPos.second,divM,divS,idx });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int answer = 0;
	vector<vector<Info>> arr(n, vector<Info>(n)); //üũ�� �迭
	for (int i = 0; i < m; i++) { //���̾ �Է�
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		fb.push({ r - 1,c - 1,m,s,d });
	}
	for (int i = 0; i < k; i++) { //k�� �̵� ���
		move(arr); //���̾ �̵�
		isDuplicated(arr); //2���̻� ���ƴ��� Ȯ�� -> ���������
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < n; jj++) {
				arr[ii][jj] = { 0,0,0,0 };
			}
		}
	}
	while (!fb.empty()) {
		fireBall cur = fb.front(); fb.pop();
		answer += cur.m;
	}
	cout << answer;
	return 0;
}