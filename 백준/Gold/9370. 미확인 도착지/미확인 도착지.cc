#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, t;
int s, g, h;
const int INF = (int)1e9;
vector<vector<pii>> adj;

vector<int> dijkstra(int st) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n + 1, INF);
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

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		adj.assign(n + 1, vector<pii>());

		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ c, b });
			adj[b].push_back({ c, a });
		}

		vector<int> fromS = dijkstra(s);
		vector<int> fromG = dijkstra(g);
		vector<int> fromH = dijkstra(h);

		vector<int> destinations;
		while (t--) {
			int cand; cin >> cand;
			if (fromS[cand] == fromS[g] + fromG[h] + fromH[cand]) destinations.push_back(cand);
			else if (fromS[cand] == fromS[h] + fromH[g] + fromG[cand]) destinations.push_back(cand);
		}

		sort(destinations.begin(), destinations.end());
		for (int x : destinations) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}