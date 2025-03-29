#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, x;
const int INF = (int)1e9;
vector<vector<pii>> adj, revAdj;

vector<int> dijkstra(int st, vector<vector<pii>>& graph) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n + 1, INF);
	dist[st] = 0;
	pq.push({ dist[st], st });

	while (!pq.empty()) {
		auto [c, cur] = pq.top(); pq.pop();
		if (dist[cur] != c) continue;
		for (auto [nc, nxt] : graph[cur]) {
			if (dist[nxt] <= dist[cur] + nc) continue;
			dist[nxt] = dist[cur] + nc;
			pq.push({ dist[nxt], nxt });
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;
	adj.assign(n + 1, vector<pii>());
	revAdj.assign(n + 1, vector<pii>());
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		revAdj[b].push_back({ c, a });
	}

	auto v1 = dijkstra(x, adj);
	auto v2 = dijkstra(x, revAdj);

	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		int d = v1[i] + v2[i];
		maxTime = max(maxTime, d);
	}
	
	cout << maxTime << '\n';
	return 0;
}