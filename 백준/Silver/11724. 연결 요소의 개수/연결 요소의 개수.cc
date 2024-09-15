#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> graph[1005];
bool vis[1005];

void dfs(int cur) {
	vis[cur] = true;
	for (int nxt : graph[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
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

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		ans++; dfs(i);
	}

	cout << ans << '\n';
	return 0;
}