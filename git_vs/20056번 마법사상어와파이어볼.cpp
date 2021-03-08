#include <bits/stdc++.h>

using namespace std;
//배열에 m,s,d,cnt
//파이어볼은 m,s,d
//이동하면서 queue에서 pop하면서 배열에 체크
//2개이상이면 나누고, 아니면 그냥 두고
//배열에 있는 값을 queue에 다 넣으면서 배열 초기화
//합쳐지는건 cnt가 2이상인지 체크하고
//방향이 모두 홀수or짝수는 홀수면 1더하고 짝수면 -1더해서
//cnt가 배열의d값이랑 같은지 다른지 체크
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

		//배열 밖으로 나가는걸 체크하기 위해 모듈러 연산
		if (ny >= n)ny = ny % n;
		else if (ny < 0)ny = (ny % n) + n;
		if (nx >= n)nx = nx % n;
		else if (nx < 0)nx = (nx % n) + n;
		if (ny == n)ny = 0;
		if (nx == n)nx = 0;
		//배열에 현재 파이어볼의 정보를 담는다
		arr[ny][nx].m += cur.m;
		arr[ny][nx].s += cur.s;
		arr[ny][nx].d += cur.d % 2 == 0 ? -1 : 1; //짝수면 -1, 홀수면 1 더하기
		arr[ny][nx].dir.push_back(cur.d);
		arr[ny][nx].cnt += 1; //겹치는지 체크를 위해 더하기
	}
}

void isDuplicated(vector<vector<Info>>& arr) {
	queue<Info> cur;
	queue<pii> curPos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Info tmp = arr[i][j];
			if (arr[i][j].cnt > 1) { //겹치는건 나눠서 넣고
				cur.push({ tmp.m, tmp.s, tmp.d, tmp.cnt }); //겹치는것을 queue에 잠시 저장
				curPos.push({ i,j });
			}
			else if (arr[i][j].cnt == 1) { //하나만 있으면 지금 넣고
				fb.push({ i,j,tmp.m,tmp.s,tmp.dir[0] }); //파이어볼에 r,c,m,s,d 저장
			}
		}
	}

	while (!cur.empty()) { //합쳐진 파이어볼을 나누는 작업
		Info tmp = cur.front(); //배열의 정보를 담을 tmp변수
		pii tmpPos = curPos.front();
		cur.pop();
		curPos.pop();
		int divM = tmp.m / 5; //질량은 질량의 합 / 5
		if (divM == 0)continue; //질량이 0이면 그냥 넘기기
		int divS = tmp.s / tmp.cnt; //속력은 속력의 합 / 합쳐진 개수
		if (tmp.d == tmp.cnt || (tmp.d * -1) == tmp.cnt) { //방향이 모두 홀/짝수일때
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
		else { //아닐때
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
	vector<vector<Info>> arr(n, vector<Info>(n)); //체크할 배열
	for (int i = 0; i < m; i++) { //파이어볼 입력
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		fb.push({ r - 1,c - 1,m,s,d });
	}
	for (int i = 0; i < k; i++) { //k번 이동 명령
		move(arr); //파이어볼 이동
		isDuplicated(arr); //2개이상 겹쳤는지 확인 -> 나누기까지
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