#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pll;

int n, m, w;
const ll INF = 1e18;
vector<vector<pll>> adj;
vector<ll> dist;

bool spfa(int st) {
	dist.assign(n + 1, INF);
	vector<bool> vis(n + 1, false);
	vector<int> cnt(n + 1, 0);
	queue<int> q;

	dist[st] = 0;
	q.push(st); vis[st] = true;
	++cnt[st];

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		vis[cur] = false;
		for (auto [nxt, cost] : adj[cur]) {
			if (dist[cur] != INF && dist[nxt] > dist[cur] + cost) {
				dist[nxt] = dist[cur] + cost;
				if (!vis[nxt]) {
					q.push(nxt); vis[nxt] = true;
					if (++cnt[nxt] >= n) return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		adj.assign(n + 1, vector<pll>());

		while (m--) {
			int a, b; ll c;
			cin >> a >> b >> c;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}

		while (w--) {
			int a, b; ll c;
			cin >> a >> b >> c;
			adj[a].push_back({ b, -c });
		}

		bool hasNegativeCycle = false;
		for (int i = 1; i <= n; i++) {
			if (spfa(i)) {
				hasNegativeCycle = true;
				break;
			}
		}

		cout << (hasNegativeCycle ? "YES\n" : "NO\n");
	}

	return 0;
}