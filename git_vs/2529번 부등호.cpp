#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k; cin >> k;
	vector<char> ins;
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> maxArr;
	vector<int> minArr;
	string maxAns = "";
	string minAns = "";
	for (int i = 0; i < k; i++) {
		char tmp; cin >> tmp;
		ins.push_back(tmp);
	}
	for (int i = 9; i >= (10-k-1); i--) maxArr.push_back(num[i]); // 9 8 7
	for (int i = 0; i <= k; i++) minArr.push_back(num[i]); // 0 1 2 
	do {
		bool flag = true;
		string tmp = "";
		for (int i = 0; i < ins.size(); i++) {
			if (ins[i] == '<') {
				if (maxArr[i] > maxArr[i + 1]) {
					flag = false;
					break;
				}
			}
			if (ins[i] == '>') {
				if (maxArr[i] < maxArr[i + 1]) {
					flag = false;
					break;
				}
			}
			if (i == ins.size() - 1) {
				for (int i = 0; i <= k; i++) {
					tmp += to_string(maxArr[i]);
				}
			}
		}
		if (flag) {
			maxAns = tmp;
			break;
		}
	} while (prev_permutation(maxArr.begin(), maxArr.end()));
	do {
		string tmp = "";
		bool flag = true;
		for (int i = 0; i < ins.size(); i++) {
			if (ins[i] == '<') {
				if (minArr[i] > minArr[i + 1]) {
					flag = false;
					break;
				}
			}
			if (ins[i] == '>') {
				if (minArr[i] < minArr[i + 1]) {
					flag = false;
					break;
				}
			}
			if (i == ins.size() - 1) {
				for (int i = 0; i <= k; i++) {
					tmp += to_string(minArr[i]);
				}
			}
		}
		if (flag) {
			minAns = tmp;
			break;
		}
	} while (next_permutation(minArr.begin(), minArr.end()));
	cout << maxAns << "\n" << minAns;
	return 0;
}