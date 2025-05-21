#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    // base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n] << '\n';
    return 0;
}