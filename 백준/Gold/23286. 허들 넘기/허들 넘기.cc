#include <bits/stdc++.h>
using namespace std;

int n, m, tc;
const int INF = (int)1e9;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> tc;
	adj.assign(n + 1, vector<int>(n + 1, INF));

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	floyd();

	while (tc--) {
		int s, e;
		cin >> s >> e;
		cout << (adj[s][e] != INF ? adj[s][e] : -1) << '\n';
	}

	return 0;
}