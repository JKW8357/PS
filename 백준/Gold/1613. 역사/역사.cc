#include <bits/stdc++.h>
using namespace std;

int n, k;
const int INF = (int)1e9;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] == -1 && adj[k][j] == -1) adj[i][j] = -1;
				if (adj[i][k] == 1 && adj[k][j] == 1) adj[i][j] = 1;
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	while (k--) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = -1;
		adj[b][a] = 1;
	}

	floyd();

	int s; cin >> s;
	while (s--) {
		int a, b;
		cin >> a >> b;
		cout << (adj[a][b] != INF ? adj[a][b] : 0) << '\n';
	}

	return 0;
}