#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int INF = (int)1e9;
vector<vector<int>> adj;

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

	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1) adj[a][b] = adj[b][a] = 0;
		else { adj[a][b] = 0; adj[b][a] = 1; }
	}

	floyd();

	int k; cin >> k;
	while (k--) {
		int s, e;
		cin >> s >> e;
		cout << adj[s][e] << '\n';
	}

	return 0;
}