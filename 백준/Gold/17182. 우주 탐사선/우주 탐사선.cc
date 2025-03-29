#include <bits/stdc++.h>
using namespace std;

int n, st;
const int INF = (int)1e9;
vector<vector<int>> adj;
vector<int> combo;

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

	cin >> n >> st; st++;
	adj.resize(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];

	floyd();

	for (int i = 1; i <= n; i++)
		if (i != st) combo.push_back(i);
	
	int minTime = INF;
	do {
		int cur = st;
		int t = 0;
		for (int nxt : combo) {
			t += adj[cur][nxt];
			cur = nxt;
		}
		minTime = min(minTime, t);
	} while (next_permutation(combo.begin(), combo.end()));

	cout << minTime << '\n';
	return 0;
}