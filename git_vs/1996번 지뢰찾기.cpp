#include <iostream>
using namespace std;

int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,1,1,1,0,-1,-1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	char map[1002][1002];
	char ans[1002][1002];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) { //char 1에서 48을 빼면 int 1
		for (int j = 1; j <= n; j++) { //숫자를 만나면 *로 만들고 패스
			if (map[i][j] == '.') {
				int num = 0;
				for (int k = 1; k <= 8; k++) {
					if (map[i + dx[k]][j + dy[k]] >= '0'&&map[i + dx[k]][j + dy[k]] <= '9') {
						num += map[i + dx[k]][j + dy[k]] - '0';
					}
				}
				if (num >= 10)ans[i][j] = 'M';
				else
					ans[i][j] = num + '0';
			}
			else ans[i][j]='*';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}