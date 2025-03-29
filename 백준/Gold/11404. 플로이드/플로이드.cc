#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
vector<vector<int>> adj;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (adj[i][j] != INF ? adj[i][j] : 0) << ' ';
		cout << '\n';
	}

	return 0;
}