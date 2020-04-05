#include <bits/stdc++.h>

using namespace std;
int n, m;

void func(vector<int> &arr, vector<bool> &use, int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	/* 각 칸의 1~n을 재귀로 돌며 사용하지 않았으면 T로 바꾸고 배열에 넣고,
	사용하고 나서는 F로 바꿔서 다음번에도 방문할 수 있도록 한다.
	*/
	for (int i = 0; i < n; i++) { 
		if (!use[i]) { //사용하지 않았으면
			arr[k] = i+1; //k번째 수에 i+1 넣기
			use[i] = true;
			func(arr, use, k + 1);
			use[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<bool> use(n, false);
	vector<int> arr(m);
	func(arr, use, 0);
	
	return 0;
}