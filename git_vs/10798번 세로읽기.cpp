#include <iostream>
#include <string>
using namespace std;

char arr[5][16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string temp = "";
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			arr[i][j] = temp[j];
		}
	}
	for (int i = 0; i < 15; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[j][i])
				cout << arr[j][i];
			else {
				cnt++;
			}
		}
	}

	return 0;
}