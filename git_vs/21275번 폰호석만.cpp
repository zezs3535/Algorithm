#include <bits/stdc++.h>

using namespace std;
string a, b;
struct ans {
	long long x;
	int a;
	int b;
};
long long cal(string s, int jin) {
	long long num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (((s[i] - 'a') + 10) >= jin)return -1;
	}
	long long tmp = 0;
	int len = s.size();
	int idx = 1;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] >= 'a' && s[i] <= 'z') { //문자일때
			num += ((s[i] - 'a') + 10) * idx;
			idx *= jin;
		}
		else if (s[i] >= '0' && s[i] <= '9') { //숫자일때
			num += (s[i] - '0') * idx;
			idx *= jin;
		}
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<ans> answer;
	int cnt = 0;
	cin >> a >> b;
	for (int i = 36; i >= 2; i--) {
		long long fnum = cal(a, i);
		if (fnum == -1)continue;
		for (int j = 36; j >= 2; j--) {
			if (i == j)continue;
			long long snum = cal(b, j);
			if (snum == -1)continue;
			if (fnum == snum) {
				cnt++;
				answer.push_back({ fnum,i,j });
			}
		}
	}
	if (answer.size() > 1)cout << "Multiple";
	else if (answer.size() == 0)cout << "Impossible";
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i].x << " " << answer[i].a << " " << answer[i].b << "\n";
		}
	}
	//for (int i = 0; i < answer.size(); i++) {
	//	cout << answer[i].x << " " << answer[i].a << " " << answer[i].b << "\n";
	//}
	return 0;
}