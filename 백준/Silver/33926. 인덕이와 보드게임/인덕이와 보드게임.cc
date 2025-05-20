#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll board[1005][1005];
bool color[1005][1005];
ll dp[1005][1005][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> color[i][j];

    dp[1][1][0] = dp[1][1][1] = board[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll mn = 0, mx = 0;

            if (i > 1 && j > 1) {
                mn = min(dp[i - 1][j][0], dp[i][j - 1][0]);
                mx = max(dp[i - 1][j][1], dp[i][j - 1][1]);
            }

            else if (i > 1) {
                mn = dp[i - 1][j][0];
                mx = dp[i - 1][j][1];
            }

            else if (j > 1) {
                mn = dp[i][j - 1][0];
                mx = dp[i][j - 1][1];
            }

            mn += board[i][j];
            mx += board[i][j];

            dp[i][j][0] = color[i][j] ? -mx : mn;
            dp[i][j][1] = color[i][j] ? -mn : mx;
        }
    }

    cout << dp[n][m][1] << '\n';
    return 0;
}