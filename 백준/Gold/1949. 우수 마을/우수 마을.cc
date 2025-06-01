#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int dp[10005][2];
vector<int> adj[10005];

void solve(int cur, int par) {
    dp[cur][0] = 0;
    dp[cur][1] = arr[cur];
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        solve(nxt, cur);
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}