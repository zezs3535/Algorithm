#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, r; cin >> n >> m >> r;
    int ans = 0;

    vector<int> item(n+1);
    vector<vector<int>> arr(n+1, vector<int>(n+1, MAX));

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
        arr[i][i] = 0;
    }

    for (int i = 0; i < r; i++) {
        int u, v, w; cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] != MAX && arr[k][j] != MAX)arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] <= m)sum += item[j];
        }
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}