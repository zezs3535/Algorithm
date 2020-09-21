#include <bits/stdc++.h>

using namespace std;

struct ball {
	int color;
	int size;
	int idx;
	int ret;
};


bool cmp(ball& a, ball& b) {
	if (a.size == b.size)return a.color < b.color;
	return a.size < b.size;
}
bool cmp2(ball& a, ball& b) {
	return a.idx < b.idx;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<ball> arr(n);
	int S[2001] = { 0, };
	int C[200001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i].color >> arr[i].size;
		arr[i].idx = i;
	}
	sort(arr.begin(), arr.end(), cmp);
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		int curColor = arr[i].color;
		int curSize = arr[i].size;

		C[curColor] += curSize;
		S[curSize] += curSize;
		totalSum += curSize;
		arr[i].ret = totalSum - C[curColor] - S[curSize] + curSize;
		if (i != 0 && arr[i].size == arr[i - 1].size && arr[i].color == arr[i - 1].color) {
			arr[i].ret = arr[i - 1].ret;
		}
	}

	sort(arr.begin(), arr.end(), cmp2);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].ret << "\n";
	}

	return 0;
}