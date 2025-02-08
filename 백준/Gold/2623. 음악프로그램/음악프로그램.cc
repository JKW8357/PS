#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int ind[1005];
int n, m;

void topologicalSort() {
	vector<int> result;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur])
			if (--ind[nxt] == 0) q.push(nxt);
	}

	if (result.size() != n) cout << 0 << '\n';
	else for (int e : result) cout << e << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int num, u, v;
		cin >> num;
		cin >> u;
		while (--num) {
			cin >> v;
			adj[u].push_back(v);
			ind[v]++;
			swap(u, v);
		}
	}

	topologicalSort();
	return 0;
}