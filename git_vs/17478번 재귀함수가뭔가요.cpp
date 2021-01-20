#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int n;

void callHyphen(int depth) {
	for (int i = 0; i < depth * 4; i++) {
		cout << "_";
	}
}

void recursive(int depth) {
	callHyphen(depth);
	cout<<"\"����Լ��� ������?\"\n";
	if (depth == n) {
		callHyphen(depth);
		cout<<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		callHyphen(depth);
		cout<<"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		callHyphen(depth);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		callHyphen(depth);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		if (depth == n)return;
		recursive(depth + 1);
	}
	callHyphen(depth);
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursive(0);
	return 0;
}