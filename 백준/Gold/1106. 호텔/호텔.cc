#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int MX = 1100;

int cost[22];
int people[22];
int dp[MX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c, n;
    cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i] >> people[i];
    fill(dp + 1, dp + MX + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = people[i]; j <= c + 100; j++)
            dp[j] = min(dp[j], dp[j - people[i]] + cost[i]);

    int ans = *min_element(dp + c, dp + MX + 1);
    cout << ans << '\n';

    return 0;
}