#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n,k;

struct belt {
	int dur;
	bool isRobot;
};

bool checkDur(deque<belt>& up, deque<belt>& down) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (up[i].dur == 0)cnt++;
		if (down[i].dur == 0)cnt++;
		if (cnt >= k)return false;
	}
	return true;
}

void moveBelt(deque<belt>& up, deque<belt>& down) {
	belt tmp = down.front();
	down.pop_front();
	up.push_front(tmp);
	tmp = up.back();
	up.pop_back();
	down.push_back(tmp);
	up.back().isRobot = false;
	up[0].isRobot = false;
}

void moveRobot(deque<belt>& up) {
	for (int i = up.size() - 1; i > 0; i--) {
		if (up[i].dur > 0) {
			if (up[i - 1].isRobot == true&&up[i].isRobot==false) {
				up[i].dur--;
				up[i].isRobot = true;
				up[i - 1].isRobot = false;
			}
		}
	}
	up.back().isRobot = false;
	up[0].isRobot = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	deque<belt> up;
	deque<belt> down;
	cin >> n >> k;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		up.push_back({ tmp,false });
	}
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		down.push_front({ tmp,false });
	}
	while (1) {
		answer++;
		moveBelt(up, down);
		moveRobot(up);
		if (up[0].isRobot == false && up[0].dur>0) {
			up[0].dur--;
			up[0].isRobot = true;
		}
		if (!checkDur(up, down))break;
	}
	cout << answer;
	return 0;
}