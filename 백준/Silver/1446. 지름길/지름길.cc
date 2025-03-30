#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int m, d;
const int MX = 10000;
const int INF = (int)1e9;
vector<vector<pii>> adj;
vector<int> dist;

void dijkstra(int st) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist.assign(MX + 1, INF);
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
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> d;
	adj.assign(MX + 1, vector<pii>());

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	for (int i = 0; i < d; i++)
		adj[i].push_back({ 1, i + 1 });

	dijkstra(0);
	cout << dist[d] << '\n';

	return 0;
}