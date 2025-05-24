#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;

char arr[3005][3005];
ll dp[3005][3005][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= 2; k++) dp[i][j][k] = (dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + MOD) % MOD;
            if (arr[i][j] == 'E') dp[i][j][0] = (dp[i][j][0] + 1) % MOD;
            if (arr[i][j] == 'S') dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0] + MOD) % MOD;
            if (arr[i][j] == 'M') dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1] + MOD) % MOD;
        }
    }
    
    cout << dp[n][m][2] << '\n';
    return 0;
}