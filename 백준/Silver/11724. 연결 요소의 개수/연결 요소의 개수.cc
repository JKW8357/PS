#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> graph[1005];
bool vis[1005];

void bfs(int v) {
	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
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
		ans++; bfs(i);
	}

	cout << ans << '\n';
	return 0;
}