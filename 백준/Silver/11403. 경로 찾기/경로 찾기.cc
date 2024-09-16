#include <bits/stdc++.h>
using namespace std;

int n;
int adj[105][105];
bool vis[105];

int dfs(int cur, int en) {
	for (int nxt = 1; nxt <= n; nxt++) {
		if (!vis[nxt] && adj[cur][nxt]) {
			vis[nxt] = true;
			if (nxt == en) return 1;
			if (dfs(nxt, en)) return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fill(vis, vis + n + 1, false);
			cout << dfs(i, j) << ' ';
		}
		cout << '\n';
	}

	return 0;
}