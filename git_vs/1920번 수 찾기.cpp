#include <bits/stdc++.h>

using namespace std;

vector<int> narray;
int n;

int binarySearch(int key) {
	int l = 0, r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r) {
		if (narray[mid] < key) {
			l = mid + 1;
			mid = (l + r) / 2;
		}
		else if(narray[mid]>key){
			r = mid - 1;
			mid = (l + r) / 2;
		}
		else if(narray[mid] == key)return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		narray.push_back(tmp);
	}
	sort(narray.begin(), narray.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << binarySearch(tmp)<<"\n";
	}
	return 0;
}