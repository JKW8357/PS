#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];

void dfs(int cur, int par) {
	p[cur] = par;
	for (int nxt : adj[cur]) {
		if (nxt == par) continue;
		dfs(nxt, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	fill(p + 1, p + n + 1, -1);
    
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);
	for (int i = 2; i <= n; i++) cout << p[i] << '\n';

	return 0;
}