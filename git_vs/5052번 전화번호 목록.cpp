#include <bits/stdc++.h>

using namespace std;
bool check = false;
class Tries {
private:
	Tries* child[10];
	bool isTerminal = false;

public:
	Tries() {
		for (int i = 0; i < 10; i++)child[i] = NULL;
	}
	~Tries() {
		for (int i = 0; i < 10; i++) {
			if (child[i] != NULL)delete child[i];
		}
	}

	void insert(string s, int idx) {
		if (idx == s.size()) {
			isTerminal = true;
			return;
		}
		if (child[s[idx] - '0'] == NULL) {
			child[s[idx] - '0'] = new Tries();
		}
		if (isTerminal) {
			check = true;
			return;
		}
		child[s[idx] - '0']->insert(s, idx + 1);
	}

	bool find(string s, int idx) {
		if (idx==s.size())return true;
		if (child[s[idx] - '0'] == NULL)return false;
		return child[s[idx] - '0']->find(s, idx + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int t; cin >> t;
	while (t--) {
		Tries trie;
		vector<string> vs;
		int n; cin >> n;
		check = false;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			vs.push_back(s);
		}
		sort(vs.begin(), vs.end());
		for (int i = 0; i < n; i++) {
			trie.insert(vs[i], 0);
		}
		if (check) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}