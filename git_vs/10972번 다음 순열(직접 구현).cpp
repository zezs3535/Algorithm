#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

bool next_per(vector<int> &a,int size) {
	int i = size - 1;
	while (i > 0&&a[i - 1] > a[i])i--;
	if (i <= 0)return false;
	int j = size - 1;
	while (a[j] <= a[i - 1])j--;
	swap(a[i - 1], a[j]);
	j = size - 1;
	while (i<j) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	if (next_per(arr,n)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}