#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int vis[100005];
int order = 0;

void dfs(int cur) {
	vis[cur] = ++order;
	for (int nxt : graph[cur])
		if (vis[nxt] == 0) dfs(nxt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
	dfs(r);
	for (int i = 1; i <= n; i++) cout << vis[i] << '\n';
	return 0;
}