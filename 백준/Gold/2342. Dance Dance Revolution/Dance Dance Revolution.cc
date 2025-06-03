#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int dp[100005][5][5];
int cost[5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 0;
    while (true) {
        int x; cin >> x;
        if (x == 0) break;
        arr[++n] = x;
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 100005 * 5 * 5, INT_MAX);
    dp[0][0][0] = 0;

    for (int i = 1; i <= 4; i++) {
        cost[i][i] = 1;
        cost[i][0] = cost[0][i] = 2;
        cost[i][(i + 1 + (int)(i >= 4)) % 5] = cost[(i + 1 + (int)(i >= 4)) % 5][i] = 3;
        cost[i][(i + 2 + (int)(i >= 3)) % 5] = cost[(i + 2) % 5 + (int)(i >= 3)][i] = 4;
    }

    for (int i = 1; i <= n; i++) {
        for (int l = 0; l <= 4; l++) {
            for (int r = 0; r <= 4; r++) {
                if (arr[i] != r && dp[i - 1][l][r] != INT_MAX)
                    dp[i][arr[i]][r] = min(dp[i][arr[i]][r], dp[i - 1][l][r] + cost[l][arr[i]]);
                if (arr[i] != l && dp[i - 1][l][r] != INT_MAX)
                    dp[i][l][arr[i]] = min(dp[i][l][arr[i]], dp[i - 1][l][r] + cost[r][arr[i]]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= 4; i++) {
        ans = min(ans, dp[n][arr[n]][i]);
        ans = min(ans, dp[n][i][arr[n]]);
    }

    cout << ans << '\n';
    return 0;
}