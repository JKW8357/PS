#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[2005];
bool vis[2005];

bool dfs(int cur, int depth) {
	if (depth == 5) return true;

	vis[cur] = true;
	for (int nxt : graph[cur]) {
		if (vis[nxt]) continue;
		if (dfs(nxt, depth + 1)) return true;
	}
	vis[cur] = false;

	return false;
}

bool solve() {
	for (int i = 0; i < n; i++) {
		if (dfs(i, 1)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << (solve() ? 1 : 0) << '\n';
	return 0;
}