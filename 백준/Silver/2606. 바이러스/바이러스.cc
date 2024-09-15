#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;

vector<int> graph[105];
bool vis[105];

void dfs(int cur) {
	vis[cur] = true;
	for (int nxt : graph[cur]) {
		if (vis[nxt]) continue;
		ans++; dfs(nxt);
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

	dfs(1);
	cout << ans << '\n';
	return 0;
}