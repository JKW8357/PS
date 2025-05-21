#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q, x, y;
unordered_map<ll, ll> dp;

ll solve(ll n) {
    if (n <= 0) return 1;
    if (dp[n]) return dp[n];
    return dp[n] = solve(n / p - x) + solve(n / q - y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p >> q >> x >> y;
    cout << solve(n) << '\n';

    return 0;
}