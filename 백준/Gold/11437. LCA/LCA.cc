#include <bits/stdc++.h>
using namespace std;

int p[50005];
int d[50005];
bool vis[50005];
vector<int> adj[50005];

void dfs(int cur, int depth) {
    vis[cur] = true;
    d[cur] = depth;
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        p[nxt] = cur;
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

    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int m; cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }

    return 0;
}