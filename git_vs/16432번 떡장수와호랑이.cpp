#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;
int n;
vector<int> arr[1001];
vector<bool> v[1001];
bool isAns = false;
string ans = "";

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

bool dfs(int idx, string check) { 
    //idx������ ������ ���鼭, check�� �ִ��� Ȯ��
    //check�� ������ �н�, ������ dfs
    //check.size()==n�̸� ���, ����bool������ üũ����
    //cout << idx;
    if (isAns)return true;
    if (idx == n) {
        isAns = true;
        ans = check;
        return true;
    }
    for (int i = 0; i < arr[idx].size(); i++) {
        if (arr[idx][i] != check[idx - 1] - '0' && isAns == false && v[idx][i] == true) {
            v[idx][i] = dfs(idx + 1, check + to_string(arr[idx][i]));
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string check = "";

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) { //�� �Է�, �湮�迭�� üũ�ϱ����� ����
            int tmp; cin >> tmp;
            arr[i].push_back(tmp);
            v[i].push_back(true);
        }
    }

    for (int i = 0; i < arr[0].size();i++) {
        v[0][i] = dfs(1, check + to_string(arr[0][i])); //ù°�� dfsŽ��
    }

    if (isAns) {
        for (char i : ans) {
            cout << i - '0' << "\n";
        }
    }
    else cout << "-1";
    return 0;
}