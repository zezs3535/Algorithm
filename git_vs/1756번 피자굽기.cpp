#include <bits/stdc++.h>

using namespace std;
vector<int> oven(300001, 1e9 + 10);
vector<int> pizza(300001, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int d, n; cin >> d >> n;
	int idx = 0;
	int ans = 0;
	stack<int> s;
	cin >> oven[0];
	for (int i = 1; i < d; i++) {
		int tmp; cin >> tmp;
		oven[i] = min(tmp, oven[i - 1]); //스택에 넣고 뒤에서부터 탐색하기때문에
		// 앞에서부터 들어오지 못하는 값이 들어오면 틀리게 되더라
		// ex) 5 5 6 7 3 2 2 -> 5 5 5 5 3 2 2 이런식으로 값을 넣어줘야함
	}

	for (int i = 0; i < n; i++)cin >> pizza[i];

	for (int i = 0; i < d; i++) {
		if (oven[i] >= pizza[idx]) { //오븐에 피자 반죽이 들어갈때
			s.push(oven[i]); //스택에 오븐 크기를 넣고
		}
		else { //안들어갈때
			if (i == 0) {
				cout << 0;
				return 0;
			}
			break;
		}
	}
	while (!s.empty() && idx < n) {
		if (s.top() >= pizza[idx]) { //쌓을수 있으면 밑의 반죽 위에 쌓이고
			ans = s.size();
			idx++;
		}
		s.pop(); //오븐에 걸리면 안걸릴때까지 오븐을 pop.. 반죽은 그대로
	}
	if (idx == n)cout << ans;
	else cout << 0;
	return 0;
}