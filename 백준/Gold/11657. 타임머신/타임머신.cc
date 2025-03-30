#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, ll> tup;

int n, m;
const int INF = (int)1e18;
vector<tup> adj;
vector<ll> dist;

bool bellmanFord(int st) {
	dist.assign(n + 1, INF);
	dist[st] = 0;

	for (int i = 1; i <= n; i++) {
		for (auto [cur, nxt, cost] : adj) {
			if (dist[cur] != INF && dist[cur] + cost < dist[nxt]) {
				dist[nxt] = dist[cur] + cost;
				if (i == n) return true;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;	
	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		adj.push_back({ a, b, c });
	}

	bool hasNegativeCycle = bellmanFord(1);
	if (hasNegativeCycle) {
		cout << -1 << '\n';
		return 0;
	}

	for (int k = 2; k <= n; k++)
		cout << (dist[k] != INF ? dist[k] : -1) << '\n';

	return 0;
}