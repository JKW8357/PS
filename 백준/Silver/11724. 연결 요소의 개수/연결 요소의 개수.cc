#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;

vector<int> graph[1005];
bool vis[1005];

void bfs() {
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		ans++;

		queue<int> q;
		q.push(i);
		vis[i] = true;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt : graph[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
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

	bfs();
	cout << ans << '\n';
	return 0;
}