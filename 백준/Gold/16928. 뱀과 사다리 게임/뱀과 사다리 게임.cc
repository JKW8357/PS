#include <bits/stdc++.h>
using namespace std;

int board[105];
int vis[105];

int bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int nxt = cur + i;
			if (board[nxt] != 0) nxt = board[nxt];
			if (vis[nxt] != -1 || nxt > 100) continue;
			vis[nxt] = vis[cur] + 1;
			q.push(nxt);
		}
	}
	return vis[100];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++) {
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	fill(vis, vis + 105, -1);
	int ans = bfs(1);
	cout << ans << '\n';
	return 0;
}