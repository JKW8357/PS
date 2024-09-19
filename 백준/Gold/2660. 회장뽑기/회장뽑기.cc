#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[55];
int dis[55];

int members[55];
vector<int> candidates;

int bfs(int st) {
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	int sc = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			if (dis[nxt] != -1) continue;
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
			sc = max(sc, dis[nxt]);
		}
	}

	return sc;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int u = 0, v = 0;
	while (true) {
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(dis + 1, dis + n + 1, -1);
		members[i] = bfs(i);
	}

	int score = *min_element(members + 1, members + n + 1);

	for (int i = 1; i <= n; i++)
		if (members[i] == score) candidates.push_back(i);
	sort(candidates.begin(), candidates.end());

	cout << score << ' ' << candidates.size() << '\n';
	for (int c : candidates) cout << c << ' ';

	return 0;
}