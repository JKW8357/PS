#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<bool> isCycle;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) { isCycle[x] = true; return; }
	if (isCycle[x] || isCycle[y]) isCycle[x] = isCycle[y] = true;
	if (p[x] < p[y]) swap(x, y);
	if (p[x] == p[y]) p[y]--;
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		p.assign(n + 1, -1);
		isCycle.assign(n + 1, false);

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			if (find(u) == find(v)) isCycle[find(u)] = true;
			else unite(u, v);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int root = find(i);
			if (i == root && !isCycle[root]) cnt++;
		}

		cout << "Case " << tc++ << ": ";
		if (cnt > 1) cout << "A forest of " << cnt << " trees.";
		else if (cnt == 1) cout << "There is one tree.";
		else cout << "No trees.";
		cout << '\n';
	}

	return 0;
}