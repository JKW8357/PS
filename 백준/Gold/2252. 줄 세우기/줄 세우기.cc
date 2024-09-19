#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[32005];
vector<int> adj[32005];
vector<int> result;

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (int i : result) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	topologicalSort();
	return 0;
}