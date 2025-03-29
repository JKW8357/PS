#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, x;
const int INF = (int)1e9;
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

	cin >> n >> m >> x;
	adj.assign(n + 1, vector<pii>());
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		int d = dijkstra(i, x) + dijkstra(x, i);
		maxTime = max(maxTime, d);
	}
	
	cout << maxTime << '\n';
	return 0;
}