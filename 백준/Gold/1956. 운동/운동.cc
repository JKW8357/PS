#include <bits/stdc++.h>
using namespace std;

int v, e;
const int INF = (int)1e9;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v >> e;
	adj.assign(v + 1, vector<int>(v + 1, INF));

	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	floyd();

	int minCycle = INF;
	for (int i = 1; i <= v; i++)
		minCycle = min(minCycle, adj[i][i]);
	cout << (minCycle != INF ? minCycle : -1) << '\n';

	return 0;
}