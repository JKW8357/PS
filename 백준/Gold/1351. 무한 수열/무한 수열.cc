#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q;
unordered_map<ll, ll> dp;

ll solve(ll n) {
    if (dp[n]) return dp[n];
    return dp[n] = solve(n / p) + solve(n / q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p >> q; dp[0] = 1;
    cout << solve(n) << '\n';

    return 0;
}