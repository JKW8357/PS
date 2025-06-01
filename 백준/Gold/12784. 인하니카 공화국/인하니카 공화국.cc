#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[1005];

int solve(int cur, int par) {
    bool isLeaf = true;
    int sum = 0;

    for (auto& [nxt, cost] : adj[cur]) {
        if (nxt == par) continue;
        isLeaf = false;
        sum += min(solve(nxt, cur), cost);
    }

    return isLeaf ? INT_MAX : sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        while (m--) {
            int u, v, d;
            cin >> u >> v >> d;
            adj[u].push_back({ v, d });
            adj[v].push_back({ u, d });
        }

        int ans = solve(1, -1);
        cout << (ans != INT_MAX ? ans : 0) << '\n';
        for (int i = 1; i <= n; i++) adj[i].clear();
    }

    return 0;
}