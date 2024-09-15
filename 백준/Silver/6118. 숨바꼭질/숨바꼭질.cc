#include <bits/stdc++.h>
using namespace std;

int max_val = 0;
vector<int> graph[20005];
int dis[20005];

void bfs(int st) {
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (dis[nxt] != -1) continue;
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
			max_val = max(max_val, dis[nxt]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill(dis + 1, dis + n + 1, -1);
	bfs(1);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] == max_val) {
			if (cnt == 0) cout << i << ' ';
			cnt++;
		}
	}

	cout << max_val << ' ' << cnt << '\n';
	return 0;
}