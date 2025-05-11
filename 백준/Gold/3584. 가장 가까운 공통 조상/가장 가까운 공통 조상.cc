#include <bits/stdc++.h>
using namespace std;

int p[10005];
int d[10005];
bool vis[10005];
vector<vector<int>> adj;

int findRoot(int cur) {
    while (p[cur] != -1) cur = p[cur];
    return cur;
}

void dfs(int cur, int depth) {
    vis[cur] = true;
    d[cur] = depth;
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt, depth + 1);
    }
}

int lca(int x, int y) {
    while (d[x] != d[y]) {
        if (d[x] > d[y]) x = p[x];
        else y = p[y];
    }
    while (x != y) {
        x = p[x];
        y = p[y];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        fill(p, p + n + 1, -1);
        fill(d, d + n + 1, 0);
        fill(vis, vis + n + 1, false);
        adj.assign(n + 1, vector<int>());

        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            p[b] = a;
        }

        dfs(findRoot(1), 0);

        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }

    return 0;
}