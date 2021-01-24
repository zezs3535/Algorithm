#include <bits/stdc++.h>

using namespace std;

int arr[4] = { 1,5,10,50 }; //로마 숫자 4개 저장

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n; //사용할 수 있는 문자의 개수
	queue<int> q; //로마 숫자 1,5,10,50을 이용하여 덧셈을 한 수 저장하는 queue
	set<int> tmp; //덧셈을 한 수를 저장하는 set (중복 방지)
	for (int i = 0; i < 4; i++)q.push(arr[i]); //로마 숫자 1 5 10 50을 q에 넣어놓는다
	for (int i = 1; i < n; i++) { //사용할 수 있는 문자의 개수만큼 루프
		while (!q.empty()) { //현재 queue에 있는 수 + 1, +5, +10, +50
			int cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				tmp.insert(cur + arr[j]); //더해진 수를 set에 저장하여 중복 방지
			}
		}
		for (auto it = tmp.begin(); it != tmp.end();it++) {
			q.push(*it); //set에 있던 수를 queue로 옮김
		}
		tmp.clear();
	}
	cout << q.size();
	return 0;
}