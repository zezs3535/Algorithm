#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n;
struct Pipe {
	long long dir[4]; //1,2,3 ������ 3��/5��/6��
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long answer = 0;
	vector<vector<Pipe>> dp(n, vector<Pipe>(n)); //dp�迭
	vector<vector<int>> arr(n, vector<int>(n, 0)); //����
	dp[0][1].dir[1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //�迭 ��ȸ
			int ny = i + 1;
			int nx = j + 1;
			if (dp[i][j].dir[1] != 0) { //�������� ���������� ��������
				if (nx < n && arr[i][nx] == 0)dp[i][nx].dir[1] += dp[i][j].dir[1]; //���������� ����
				if (nx < n && ny < n && arr[ny][nx] == 0 && arr[ny][j] == 0 && arr[i][nx] == 0)dp[ny][nx].dir[2] += dp[i][j].dir[1]; //�����ʾƷ��� ����
			}
			if (dp[i][j].dir[2] != 0) { //�������� �����ʾƷ��� ��������
				if (nx < n && arr[i][nx] == 0)dp[i][nx].dir[1] += dp[i][j].dir[2]; //���������� ����
				if (nx < n && ny < n && arr[ny][nx] == 0 && arr[ny][j] == 0 && arr[i][nx] == 0)dp[ny][nx].dir[2] += dp[i][j].dir[2]; //�����ʾƷ��� ����
				if (ny < n && arr[ny][j] == 0)dp[ny][j].dir[3] += dp[i][j].dir[2];
			}
			if (dp[i][j].dir[3] != 0) { //�������� �Ʒ��� ������
				if (nx < n && ny < n && arr[ny][nx] == 0 && arr[ny][j] == 0 && arr[i][nx] == 0)dp[ny][nx].dir[2] += dp[i][j].dir[3]; //�����ʾƷ��� ����
				if (ny < n && arr[ny][j] == 0)dp[ny][j].dir[3] += dp[i][j].dir[3];
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		answer += dp[n - 1][n - 1].dir[i];
	}
	cout << answer;
	return 0;
}