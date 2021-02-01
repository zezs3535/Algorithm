#include <bits/stdc++.h>

using namespace std;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int baduk[25][25];
int n;
int answer = 0;

void search(int ypos, int xpos, int turn) {
    int curColor = baduk[ypos][xpos];
    for (int idx = 0; idx < 8; idx++) {
        int cnt = 0;
        for (int i = 1; i <= 5; i++) {
            int ny = ypos + dy[idx] * i;
            int nx = xpos + dx[idx] * i;
            if (ny >= 20 || ny < 1 || nx >= 20 || nx < 1)break;
            if (baduk[ny][nx] == curColor) {
                cnt++;
                continue;
            }
            break;
        }
        for (int i = 1; i <= 5; i++) {
            int by = ypos + (dy[(idx + 4) % 8] * i);
            int bx = xpos + (dx[(idx + 4) % 8] * i);
            if (by >= 20 || by < 1 || bx >= 20 || bx < 1)break;
            if (baduk[by][bx] == curColor) {
                cnt++;
                continue;
            }
            break;
        }
        if (cnt >= 5) {
            continue;
        }
        else if (cnt == 4) {
            answer = turn;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n <= 8) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int ypos, xpos;
        cin >> ypos >> xpos;
        if (i % 2 == 1) {
            baduk[ypos][xpos] = 1; //1 Èæ
        }
        else {
            baduk[ypos][xpos] = 2; //2 ¹é
        }
        if (i <= 8)continue;
        search(ypos, xpos, i);
        if (answer > 0)break;
    }
    if (answer > 0)cout << answer;
    else {
        cout << "-1";
    }
    return 0;
}