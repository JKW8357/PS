#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int solve(int n) {
    if (dp[n] != -1) return dp[n];
    
    dp[n] = solve(n - 1) + 1;
    if (n % 3 == 0) dp[n] = min(dp[n], solve(n / 3) + 1);
    if (n % 2 == 0) dp[n] = min(dp[n], solve(n / 2) + 1);

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    fill(dp + 1, dp + n + 1, -1);
    dp[1] = 0;
    cout << solve(n) << '\n';

    return 0;
}