#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int LOG = 20;

int n;
int p[MAXN][LOG];
int d[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int cur, int depth) {
    vis[cur] = true;
    d[cur] = depth;
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        p[nxt][0] = cur;
        dfs(nxt, depth + 1);
    }
}

void setParent() {
    dfs(1, 0);
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
}

int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--)
        if (d[y] - d[x] >= (1 << i)) y = p[y][i];
    
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }

    return p[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    setParent();

    int m; cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }

    return 0;
}