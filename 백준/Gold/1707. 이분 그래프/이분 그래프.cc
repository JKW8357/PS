#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<vector<int>> graph;
vector<int> vis;

bool dfs(int cur, int color) {
	vis[cur] = color;
	for (int nxt : graph[cur]) {
		if (vis[nxt] == color) return false;
		else if (!vis[nxt] && !dfs(nxt, 3 - color)) return false;
	}
	return true;
}

bool isBipartite() {
	for (int i = 1; i <= v; i++) {
		if (vis[i]) continue;
		if (!dfs(i, 1)) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		cin >> v >> e;

		graph.assign(v + 1, vector<int>());
        vis.assign(v + 1, 0);

		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		cout << (isBipartite() ? "YES" : "NO") << '\n';
	}

	return 0;
}