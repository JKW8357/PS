#include <bits/stdc++.h>
using namespace std;

int n, m, r;
const int INF = (int)1e9;
vector<vector<int>> adj;
vector<int> items;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> r;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	items.resize(n + 1);
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	for (int i = 1; i <= n; i++) cin >> items[i];

	while (r--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (adj[a][b] > c) {
			adj[a][b] = c;
			adj[b][a] = c;
		}
	}

	floyd();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int itemsCnt = 0;
		for (int j = 1; j <= n; j++)
			if (adj[i][j] <= m) itemsCnt += items[j];
		ans = max(ans, itemsCnt);
	}

	cout << ans << '\n';
	return 0;
}