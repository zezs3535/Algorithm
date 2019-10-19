#include <iostream>
#include <algorithm>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a;
	int n, k;
	int t;
	cin >> n >> k;
	for (int i = 0; i < n;i++) {
		cin >> t;
		a.push_back(t);
	}

	sort(a.begin(), a.end());
	cout << a[k - 1];
	
	return 0;
}