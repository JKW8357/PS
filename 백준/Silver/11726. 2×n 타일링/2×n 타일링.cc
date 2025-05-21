#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[n] << '\n';
    return 0;
}