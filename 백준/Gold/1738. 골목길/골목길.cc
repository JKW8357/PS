#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
const int INF = (int)1e9;
vector<vector<pii>> adj;
vector<int> dist, pre;

void bellmanFord(int st) {
	dist.assign(n + 1, -INF);
	pre.assign(n + 1, -1);
	dist[st] = 0;

	for (int i = 1; i <= n; i++) {
		for (int cur = 1; cur <= n; cur++) {
			if (dist[cur] == -INF) continue;
			for (auto [nxt, cost] : adj[cur]) {
				if (dist[nxt] < dist[cur] + cost) {
					dist[nxt] = dist[cur] + cost;
					pre[nxt] = cur;
					if (i == n) dist[nxt] = INF;
				}
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

	bellmanFord(1);

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