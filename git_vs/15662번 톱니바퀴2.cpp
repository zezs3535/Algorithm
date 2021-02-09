#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int m;

void shiftQueue(deque<char>& dq, int dir) {
	char tmp;
	if (dir > 0) {
		tmp = dq.back();
		dq.pop_back();
		dq.push_front(tmp);
	}
	else {
		tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}
}

//재귀로 움직이려는 톱니바퀴의 왼쪽으로 쭉 확인
void shiftLeftQueue(vector<deque<char>>& arr, int target, int dir) {
	if (target < 0)return;
	if (arr[target][2] == arr[target + 1][6]) {
		return;
	}
	else {
		shiftLeftQueue(arr, target - 1, (dir > 0) ? -1 : 1);
		shiftQueue(arr[target], dir);
	}
}

//톱니바퀴의 오른쪽으로 쭉 확인
void shiftRightQueue(vector<deque<char>>& arr, int target, int dir) {
	if (target > m-1)return;
	if (arr[target][6] == arr[target - 1][2]) {
		return;
	}
	else {
		shiftRightQueue(arr, target + 1, (dir > 0) ? -1 : 1);
		shiftQueue(arr[target], dir);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m;
	vector<deque<char>> arr(m);
	int answer = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 8; j++) {
			char tmp; cin >> tmp;
			arr[i].push_back(tmp);
		}
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int target, dir;
		cin >> target >> dir;
		target--;
		shiftLeftQueue(arr, target - 1, (dir > 0) ? -1 : 1);
		shiftRightQueue(arr, target + 1, (dir > 0) ? -1 : 1);
		shiftQueue(arr[target], dir);
	}
	for (int i = 0; i < m; i++) {
		if (arr[i][0] == '1')answer++;
	}
	cout << answer;
	return 0;
}