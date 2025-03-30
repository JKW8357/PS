#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
const int INF = (int)1e9;
vector<vector<pii>> adj;
vector<int> dist, pre;

void bellmanFord() {
	dist.assign(n + 1, -INF);
	pre.assign(n + 1, -1);
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int u = 1; u <= n; u++) {
			if (dist[u] == -INF) continue;
			for (auto [v, cost] : adj[u]) {
				if (dist[v] < dist[u] + cost) {
					dist[v] = dist[u] + cost;
					pre[v] = u;
					if (i == n) dist[v] = INF;
				}
			}
		}
	}

	for (int u = 1; u <= n; u++) {
		if (dist[u] == -INF) continue;
		for (auto [v, cost] : adj[u]) {
			if (dist[v] < dist[u] + cost) {
				dist[v] = INF;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	adj.assign(n + 1, vector<pii>());
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	bellmanFord();

	if (dist[n] == INF || dist[n] == -INF) {
		cout << -1 << '\n';
		return 0;
	}

	vector<int> path;
	int cur = n;
	while (cur != -1) {
		path.push_back(cur);
		cur = pre[cur];
	}
	reverse(path.begin(), path.end());
	for (int x : path) cout << x << ' ';

	return 0;
}