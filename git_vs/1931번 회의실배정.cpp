#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	//정렬 기준을 세우는 함수,
	//a와 b의 끝나는 시간이 같으면 시작시간을 오름차순으로 정렬한다
	//그게 아니면 끝나는시간 오름차순 정렬
	if (a.second == b.second)return a.first < b.first;
	else {
		return a.second < b.second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0;
	int now = 0;
	cin >> n;
	vector<pair<int, int>> a(n); //pair<int,int>를 자료형으로 하는 vector n개 생성
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (now <= a[i].first) {
			now = a[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}