#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

int n, st, en, m;
const ll INF = (int)1e9;
vector<vector<pil>> adj;
vector<ll> dist, earnings;

void bellmanFord(int st) {
	dist.assign(n, -INF);
	dist[st] = earnings[st];

	for (int i = 1; i <= n; i++) {
		for (int cur = 0; cur < n; cur++) {
			if (dist[cur] == -INF) continue;
			for (auto [nxt, cost] : adj[cur]) {
				if (dist[nxt] >= dist[cur] + earnings[nxt] - cost) continue;
				dist[nxt] = dist[cur] + earnings[nxt] - cost;
				if (i == n) dist[nxt] = INF;
			}
		}
	}

	queue<int> q;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (dist[i] == INF) {
			q.push(i);
			visited[i] = true;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto [nxt, cost] : adj[cur]) {
			if (dist[nxt] != INF) dist[nxt] = INF;
			if (visited[nxt]) continue;
			visited[nxt] = true;
			q.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> st >> en >> m;
	adj.assign(n, vector<pil>());
	while (m--) {
		int a, b; ll c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	earnings.resize(n);
	for (int i = 0; i < n; i++) cin >> earnings[i];

	bellmanFord(st);

	if (dist[en] == -INF) cout << "gg" << '\n';
	else if (dist[en] == INF) cout << "Gee" << '\n';
	else cout << dist[en] << '\n';

	return 0;
}