#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = (int)1e9;
vector<vector<int>> adj, nxt;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					adj[j][i] = adj[j][k] + adj[k][i];
					nxt[i][j] = nxt[i][k];
					nxt[j][i] = nxt[j][k];
				}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	nxt.assign(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (adj[a][b] > c) {
			adj[a][b] = c;
			adj[b][a] = c;
			nxt[a][b] = b;
			nxt[b][a] = a;
		}
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << '-' << ' ';
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}