#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MAX;
int adj[12][12];

void dfs(int cur, int vis, int total) {
	if (vis == (1 << n) - 1) {
		if (adj[cur][0]) ans = min(ans, total + adj[cur][0]);
		return;
	}

	for (int nxt = 0; nxt < n; nxt++) {
		if (!adj[cur][nxt] || (vis & (1 << nxt))) continue;
		dfs(nxt, vis | (1 << nxt), total + adj[cur][nxt]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	dfs(0, 1, 0);

	cout << ans << '\n';
	return 0;
}