#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	for (int test = 1; test <= t; test++) {
		int n, k;
		int answer = 0;
		cin >> n >> k;
		deque<char> arr(n); //deque선언 ( 양방향 큐와 같은 자료구조)
		vector<int> check;
		
		for (int i = 0; i < n; i++) {
			cin >> arr[i]; //입력
		}
		int seq = n / 4;
		deque<int> hexa(seq); //16진수로 바꿀때 곱할 수
		int mul = 1;
		for (int i = 0; i < seq; i++) {
			hexa.push_front(mul);
			mul *= 16;
		}
		for (int q = 0; q < n - 1; q++) { //한칸씩 옆으로 미는 것
			for (int i = 0; i < 4; i++) {
				int pwd = 0;
				for (int j = 0 + seq * i; j < (i + 1) * seq; j++) { //[0,1,2] , [3,4,5], [6,7,8], [9,10,11]
					if (arr[j] >= '0' && arr[j] <= '9')pwd += ((arr[j] - '0') * hexa[j % seq]);
					else if (arr[j] >= 'A' && arr[j] <= 'F')pwd += ((arr[j] - 55) * hexa[j % seq]);
				}
				bool flag = true;
				for (int i = 0; i < check.size(); i++) {
					if (check[i] == pwd) {
						flag = false;
						break;
					}
				}
				if (flag)check.push_back(pwd);
			}
			char tmp = arr[n - 1];
			arr.pop_back();
			arr.push_front(tmp);
		}
		sort(check.begin(), check.end(), cmp);
		cout << "#" << test << " " << check[k-1]<<"\n";
	}

	return 0;
}