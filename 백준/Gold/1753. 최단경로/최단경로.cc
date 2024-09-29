#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define W first
#define V second

int v, e, st;
vector<pii> adj[20005];
int d[20005];

void dijkstra(int st) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(d, d + v + 1, INT_MAX);
	d[st] = 0;
	pq.push({ d[st],st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop(); 
		if (d[cur.V] != cur.W) continue;

		for (auto nxt : adj[cur.V]) {
			if (d[nxt.V] <= d[cur.V] + nxt.W) continue;
			d[nxt.V] = d[cur.V] + nxt.W;
			pq.push({ d[nxt.V],nxt.V });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e >> st;
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	dijkstra(st);
	for (int i = 1; i <= v; i++) {
		if (d[i] == INT_MAX) cout << "INF\n";
		else cout << d[i] << "\n";
	}

	return 0;
}