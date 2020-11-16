#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

struct numList {
	int value;
	int dp;
	vector<int> ans;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int maxDp = 0;
	int maxIdx = 0;
	vector<numList> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].value;
		arr[i].dp = 1;
	}
	arr[0].ans.push_back(arr[0].value);
	for (int i = 1; i < n; i++) {
		maxDp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i].value > arr[j].value) {
				if (maxDp <= arr[j].dp) {
					maxDp = arr[j].dp;
					maxIdx = j;
				}
			}
		}
		arr[i].dp = maxDp + 1;
		if(maxDp!=0)for (auto idx : arr[maxIdx].ans)arr[i].ans.push_back(idx);
		arr[i].ans.push_back(arr[i].value);
	}
	int ansDp = 0;
	int ansIdx = 0;
	for (int i = 0; i < n; i++) {
		if (ansDp <= arr[i].dp) {
			ansDp = arr[i].dp;
			ansIdx = i;
		}
	}
	cout << ansDp << "\n";
	for (auto idx : arr[ansIdx].ans)cout << idx << " ";
	
	return 0;
}