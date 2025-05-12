#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (int)1e9 + 9;

ll dp[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}