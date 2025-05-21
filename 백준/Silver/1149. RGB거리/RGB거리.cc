#include <bits/stdc++.h>
using namespace std;

int dp[1005][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        for (int j = 0; j < 3; j++) {
            dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = g + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << min({ dp[n][0], dp[n][1], dp[n][2] }) << '\n';
    return 0;
}