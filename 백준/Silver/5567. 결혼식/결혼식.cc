#include <bits/stdc++.h>
using namespace std;

vector<int> graph[505];
int dis[505];

int bfs(int st) {
	queue<int> q;
	q.push(st);

	dis[st] = 0;
	int ans = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (dis[nxt] != -1) continue;
			dis[nxt] = dis[cur] + 1;
			if (dis[nxt] <= 2) {
				q.push(nxt);
				ans++;
			}
		}
	}

	return ans;
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

	fill(dis, dis + n + 1, -1);
	cout << bfs(1) << '\n';
	return 0;
}