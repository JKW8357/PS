#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool walls[35][35];
ll dp[35][35][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> walls[i][j];

    dp[1][2][0] = 1;
    for (int j = 3; j <= n - 1; j++)
        if (!walls[1][j]) dp[1][j][0] = dp[1][j - 1][0];

    for (int i = 2; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (walls[i][j]) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            if (!walls[i - 1][j] && !walls[i][j - 1]) dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
        }
    }

    ll ans = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ans << '\n';
    return 0;
}