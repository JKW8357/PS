#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int halve[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len % 2 == 0) {
                halve[i][j] = halve[i + 1][j - 1] + (int)(s[i] == s[j]);
                dp[i][j] = max({ dp[i][j - 1], dp[i + 1][j], halve[i][j]});
            }
            else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << dp[l][r] << '\n';
    }

    return 0;
}