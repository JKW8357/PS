#include <bits/stdc++.h>
using namespace std;

int n, k, w;
int d[1005];
int dp[1005];
vector<int> adj[1005];

int solve(int cur) {
    if (dp[cur] != -1) return dp[cur];
    dp[cur] = 0;
    for (int pre : adj[cur]) dp[cur] = max(dp[cur], solve(pre));
    dp[cur] += d[cur];
    return dp[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        for (int i = 1; i <= 1000; i++) {
            dp[i] = -1;
            adj[i].clear();
        }
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> d[i];
        while (k--) {
            int x, y;
            cin >> x >> y;
            adj[y].push_back(x);
        }
        cin >> w;
        cout << solve(w) << '\n';
    }

    return 0;
}