#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> query(n,0);
	int alpha;
	for (int i = 0; i < 26; i++) {
		alpha |= (1 << i);    //alpha를 111111111111111111111 로 값을 준다
	}

	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			query[i] |= 1 << (tmp[j]-'a');	//문자열들을 int로 비트마스킹
		}
	}

	for (int i = 0; i < m; i++) {
		int cnt = 0;
		int o;
		char x;
		cin >> o >> x;
		alpha ^= 1 << (x - 'a');      //o가 1일땐 x를 기억하고 있던게 보장, o가 0일땐 x를 잊고있던게 보장되기 때문에
										  //o의 값에 관계없이 1<<(x-'a')를 반전시켜주면 된다
		for (int j = 0; j < n; j++) { 
			if ((query[j] & alpha) == query[j]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}