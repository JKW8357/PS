#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, e;
const int INF = (int)1e8;
vector<vector<pii>> adj;
vector<int> dist;

int dijkstra(int st, int en) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist.assign(n + 1, INF);
	dist[st] = 0;
	pq.push({ dist[st], st });

	while (!pq.empty()) {
		auto [c, cur] = pq.top(); pq.pop();
		if (dist[cur] != c) continue;
		for (auto [nc, nxt] : adj[cur]) {
			if (dist[nxt] <= dist[cur] + nc) continue;
			dist[nxt] = dist[cur] + nc;
			pq.push({ dist[nxt], nxt });
		}
	}

	return dist[en];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;
	adj.assign(n + 1, vector<pii>());
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int a1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
	int a2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);
	int ans = min(a1, a2);
	cout << (ans < INF ? ans : -1) << '\n';

	return 0;
}