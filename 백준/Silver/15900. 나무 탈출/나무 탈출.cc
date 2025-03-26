#include <bits/stdc++.h>
using namespace std;

bool vis[500005];
vector<int> adj[500005];

int dfs(int cur, int dist) {
	int result = 0;
	bool isLeaf = true;

	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		isLeaf = false;
		vis[nxt] = true;
		result += dfs(nxt, dist + 1);
	}

	return isLeaf ? dist : result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vis[1] = true;
	int cnt = dfs(1, 0);
	cout << (cnt % 2 ? "Yes" : "No") << '\n';
	return 0;
}