#include <bits/stdc++.h>
using namespace std;

int mxCost = 0;
int mxNode = -1;
bool vis[10005];
vector<pair<int, int>> adj[10005];

void dfs(int cur, int cost) {
	vis[cur] = true;
	if (mxCost < cost) {
		mxCost = cost;
		mxNode = cur;
	}

	for (auto& [nxt, nxtCost] : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = true;
		dfs(nxt, cost + nxtCost);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	dfs(1, 0);
	fill(vis, vis + n + 1, false);
	dfs(mxNode, 0);
	cout << mxCost << '\n';

	return 0;
}