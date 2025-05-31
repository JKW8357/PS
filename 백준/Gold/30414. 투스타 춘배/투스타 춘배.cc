#include <bits/stdc++.h>
using namespace std;
const int MX = 100000;

int arr[MX + 5];
vector<int> adj[MX + 5];

int dfs(int cur, int par) {
    int sum = 0;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        sum += dfs(nxt, cur);
    }
    int need = max(sum + arr[cur], 0);
    return need;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, st;
    cin >> n >> st;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] -= x;
        arr[i] *= -1;
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(st, -1) << '\n';
    return 0;
}