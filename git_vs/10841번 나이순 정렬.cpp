#include <bits/stdc++.h>

using namespace std;

struct member {
	int age;
	string name;
	int cnt;
};

bool cmp(member& a, member& b) {
	if (a.age == b.age)return a.cnt < b.cnt;
	else {
		return a.age < b.age;
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<member> mem(n);
	for (int i = 0; i < n; i++) {
		mem[i].cnt = i;
		cin >> mem[i].age >> mem[i].name;
	}
	sort(mem.begin(), mem.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << mem[i].age << " " << mem[i].name<<"\n";
	}
	return 0;
}