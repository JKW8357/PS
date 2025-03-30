#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = (int)1e9;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] == INF || adj[k][j] == INF) continue;
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, INF));

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (adj[a][b] > c) adj[a][b] = c;
	}

	floyd();

	for (int k = 1; k <= n; k++) {
		if (adj[1][k] != INF && adj[k][k] < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int k = 2; k <= n; k++)
		cout << (adj[1][k] != INF ? adj[1][k] : -1) << '\n';

	return 0;
}