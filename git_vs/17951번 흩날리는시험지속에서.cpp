#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	int ans = 0;
	int l = 0;
	int r = 0;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)cin >> arr[i];
	
	for (int i = 0; i < n; i++)r += arr[i];

	while (l <= r) {
		int cnt = 0;
		int sum = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			sum += arr[i]; //각 원소의 합을 sum에 더함
			if (sum >= mid) {  //sum이 mid보다 크거나 같아지면 구간을 하나 나눈다
				sum = 0;
				cnt++; //구간++
			}
		}
		if (cnt >= k) { //구간이 K보다 많으면 점수대를 높여서 더 적은 구간이 생기게
			l = mid+1;
		}
		if (cnt < k) { //구간이 K보다 적으면 점수대를 낮춰서 더 많은 구간이 생기게
			r = mid-1;
		}
		
	}
	cout << r; //답이 r인 이유는 .. l과 r값을 조절해주다가 while문을 나오는 순간이 l이 r보다 커질때.. 마지막에 l값은 바뀌고 r값은 그대로니까 r값을 출력
	return 0;
}