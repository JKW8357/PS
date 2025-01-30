#include <bits/stdc++.h>
using namespace std;

int subTreeSize[100005];
vector<int> p(100005, -1);
vector<int> c[100005];

int dfs(int cur) {
	subTreeSize[cur] = 1;
	for (int nxt : c[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		subTreeSize[cur] += dfs(nxt);
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
		c[u].push_back(v);
		c[v].push_back(u);
	}

	dfs(r);

	while (q--) {
		int u; cin >> u;
		cout << subTreeSize[u] << '\n';
	}

	return 0;
}