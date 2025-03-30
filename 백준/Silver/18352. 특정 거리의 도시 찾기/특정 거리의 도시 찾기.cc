#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, x;
const int INF = (int)1e9;
vector<vector<pii>> adj;
vector<int> dist;

void dijkstra(int st) {
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
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k >> x;
	adj.assign(n + 1, vector<pii>());

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({ 1, v });
	}

	dijkstra(x);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (dist[i] == k) ans.push_back(i);
	if (ans.empty()) cout << -1 << '\n';
	else for (int i : ans) cout << i << '\n';

	return 0;
}