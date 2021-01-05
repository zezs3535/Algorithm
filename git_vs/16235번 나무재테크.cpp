#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int dx[8] = { 1,0,-1,-1,-1,0,1,1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int arr[11][11] = { 0, };
int feed[11][11] = { 0, };
int n, m, k;
struct treeInfo {
	int y;
	int x;
	int age;
};
bool cmp(treeInfo& a, treeInfo& b) {
	return a.age < b.age;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	deque<treeInfo> tree(m);
	deque<treeInfo> tmp;
	deque<treeInfo> death;
	for (int i = 0; i < n; i++) { //�� ���� �Է�
		for (int j = 0; j < n; j++) {
			cin >> feed[i][j];
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) { //���� ���� �Է�
		cin >> tree[i].y >> tree[i].x >> tree[i].age;
		tree[i].y--;
		tree[i].x--;
	}
	sort(tree.begin(), tree.end(), cmp); //���� ��ͺ���
	for (int i = 0; i < k; i++) { //K�� ���� ����
		//��
		while(!tree.empty()) { //������ ���鼭
			int cx = tree.front().x;
			int cy = tree.front().y;
			if (arr[cy][cx] >= tree.front().age) { //����� ����ϸ� �Դ´�
				arr[cy][cx] -= tree.front().age;
				tree.front().age++;
				treeInfo t = tree.front();
				tree.pop_front();
				tmp.push_back(t);
			}
			else { //����� �����ϸ�?
				treeInfo t = tree.front();
				tree.pop_front();
				t.age = t.age / 2;
				death.push_back(t);
			}
		}
		while (!tmp.empty()) {
			treeInfo t = tmp.front();
			tree.push_back(t);
			tmp.pop_front();
		}

		//����
		while (!death.empty()) {
			treeInfo t = death.front();
			arr[t.y][t.x] += t.age;
			death.pop_front();
		}

		//����
		for (int j = 0; j < tree.size(); j++) {
			if (tree[j].age % 5 == 0) { //5�� ����̸�
				for (int idx = 0; idx < 8; idx++) {
					int ny = tree[j].y + dy[idx];
					int nx = tree[j].x + dx[idx];
					if (ny >= n || nx >= n || ny < 0 || nx < 0)continue;
					tmp.push_back({ ny,nx,1 }); //���̰� 1�� ���� �߰�
				}
			}
		}
		while (!tmp.empty()) {
			treeInfo t = tmp.front();
			tree.push_front(t);
			tmp.pop_front();
		}

		//�ܿ�
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				arr[j][l] += feed[j][l];
			}
		}
	}
	cout << tree.size();
	return 0;
}