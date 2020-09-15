#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8] = { 0 };
bool use[8] = { false };
void search(int depth) {
	if (depth == m) {
		for (int i = 0; i < m - 1; i++) {
			if (arr[i] > arr[i + 1])return;
		}
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!use[i]) {
				arr[depth] = i + 1;
				use[i] = true;
				search(depth + 1);
				use[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	search(0);

	return 0;
}