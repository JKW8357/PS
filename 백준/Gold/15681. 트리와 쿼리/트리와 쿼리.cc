#include <bits/stdc++.h>
using namespace std;

int subTreeSize[100005];
vector<int> p(100005, -1);
vector<int> adj[100005];

int countSubtreeNode(int cur) {
	subTreeSize[cur] = 1;
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		subTreeSize[cur] += countSubtreeNode(nxt);
	}
	return subTreeSize[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	countSubtreeNode(r);

	while (q--) {
		int u; cin >> u;
		cout << subTreeSize[u] << '\n';
	}

	return 0;
}