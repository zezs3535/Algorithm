/* 1991번 트리순회 전위 중위 후위 순
    A-'A' = 0						*/

#include <iostream>

using namespace std;

int tree[30][2] = { 0, };

void preOrder(int x) {
	cout << char(x+'A');
	if (tree[x][0] != -1)preOrder(tree[x][0]);
	if (tree[x][1] != -1)preOrder(tree[x][1]);
}
void inOrder(int x) {
	if (tree[x][0] != -1)inOrder(tree[x][0]);
	cout << char(x + 'A');
	if (tree[x][1] != -1)inOrder(tree[x][1]);
}
void postOrder(int x) {
	if (tree[x][0] != -1)postOrder(tree[x][0]);
	if (tree[x][1] != -1)postOrder(tree[x][1]);
	cout << char(x + 'A');
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		if (y == '.')tree[x - 'A'][0] = -1;
		else {
			tree[x - 'A'][0] = y - 'A';
		}
		if (z == '.')tree[x - 'A'][1] = -1;
		else {
			tree[x - 'A'][1] = z - 'A';
		}
	}
	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";
	return 0;
}