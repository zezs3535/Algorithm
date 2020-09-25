#include <bits/stdc++.h>

using namespace std;
int n, m;
struct Node {
	int indegree=0;
	bool use = false;
	vector<int> outdegree;
};

void topoSort(vector<Node> node) {
	vector<int> answer;
	queue<int> indegreeZero;
	for (int i = 1; i <= n; i++) {
		if (node[i].indegree == 0) {
			indegreeZero.push(i);
			node[i].use = true;
		}
	}
	while (!indegreeZero.empty()) {
		int tmp;
		tmp = indegreeZero.front();
		indegreeZero.pop();
		answer.push_back(tmp);
		for (auto i : node[tmp].outdegree) {
			node[i].indegree--;
			if (node[i].indegree == 0 && node[i].use == false) {
				node[i].use = true;
				indegreeZero.push(i);
			}
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i]<<" ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<Node> node(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].outdegree.push_back(b);
		node[b].indegree++;
	}
	topoSort(node);
	return 0;
}