#include <bits/stdc++.h>
using namespace std;

int start, target;
bool vis[1005];
vector<pair<int, int>> adj[1005];

int dfs(int cur, int dist) {
	if (cur == target) return dist;

	for (auto& [nxt, nxtDist] : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = true;
		int result = dfs(nxt, dist + nxtDist);
		if (result != -1) return result;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	while (m--) {
		fill(vis, vis + n + 1, false);
		cin >> start >> target;
		vis[start] = true;
		cout << dfs(start, 0) << '\n';
	}

	return 0;
}