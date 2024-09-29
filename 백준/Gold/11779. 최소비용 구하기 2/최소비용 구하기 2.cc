#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define W first
#define V second

int v, e, st, en;
vector<pii> adj[1005];
int dis[1005];
int pre[1005];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(dis, dis + v + 1, INT_MAX);
	dis[st] = 0;
	pq.push({ dis[st],st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dis[cur.V] != cur.W) continue;

		for (auto nxt : adj[cur.V]) {
			if (dis[nxt.V] <= dis[cur.V] + nxt.W) continue;
			dis[nxt.V] = dis[cur.V] + nxt.W;
			pre[nxt.V] = cur.V;
			pq.push({ dis[nxt.V],nxt.V });
		}
	}
}

void trace() {
	vector<int> path;
	int cur = en;

	while (cur != st) {
		path.push_back(cur);
		cur = pre[cur];
	}

	path.push_back(cur);
	reverse(path.begin(), path.end());

	cout << path.size() << '\n';
	for (auto x : path) cout << x << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	cin >> st >> en;

	dijkstra();
	cout << dis[en] << '\n';
	trace();

	return 0;
}