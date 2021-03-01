#include <iostream>

using namespace std;

void go(int arr[3][3]) {
	arr[1][1] = 1;
}

int main() {

	int arr[3][3];
	go(arr);
	cout << arr[1][1];
	return 0;
}