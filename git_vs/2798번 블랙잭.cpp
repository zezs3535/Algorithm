#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	int max = 0;
	cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) { 
		cin >> arr[i];
	}
	for (int i = 0; i < n - 2; i++) {//i는 0~n-3 j는 1~n-2 k는 2~n-1까지
		for (int j = i+1; j < n - 1; j++) {
			for (int k = j+1; k < n; k++) {
				if (max < (arr[i] + arr[j] + arr[k]) && (arr[i] + arr[j] + arr[k]) < m) {
					max = arr[i] + arr[j] + arr[k];
				}
				if (m == (arr[i] + arr[j] + arr[k])) {
					cout << m;
					return 0;
				}
			}
		}
	}
	cout << max;
	return 0;
}