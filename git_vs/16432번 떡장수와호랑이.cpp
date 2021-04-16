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
    //idx일차의 떡들을 돌면서, check에 있는지 확인
    //check에 있으면 패스, 없으면 dfs
    //check.size()==n이면 출력, 전역bool변수로 체크하자
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
        for (int j = 0; j < m; j++) { //떡 입력, 방문배열도 체크하기위해 생성
            int tmp; cin >> tmp;
            arr[i].push_back(tmp);
            v[i].push_back(true);
        }
    }

    for (int i = 0; i < arr[0].size();i++) {
        v[0][i] = dfs(1, check + to_string(arr[0][i])); //첫째날 dfs탐색
    }

    if (isAns) {
        for (char i : ans) {
            cout << i - '0' << "\n";
        }
    }
    else cout << "-1";
    return 0;
}