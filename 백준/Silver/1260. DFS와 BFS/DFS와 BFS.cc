#include <bits/stdc++.h>
using namespace std;

int n, m, v;

vector<int> graph[1005];
bool vis[1005];

void dfs(int cur) {
	vis[cur] = true;
	cout << cur << ' ';
	for (int nxt : graph[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = true;
	cout << st << ' ';
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			cout << nxt << ' ';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> v;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	fill(vis + 1, vis + n + 1, false);
	cout << '\n';
	bfs(v);

	return 0;
}