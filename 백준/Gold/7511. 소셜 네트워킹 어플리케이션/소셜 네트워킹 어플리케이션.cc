#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (p[x] < p[y]) swap(x, y);
	if (p[x] == p[y]) p[y]--;
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cout << "Scenario " << t << ":\n";
		int n, k; cin >> n >> k;
		p.resize(n);
		p.assign(n, -1);

		while (k--) {
			int a, b; cin >> a >> b;
			unionSets(a, b);
		}
		
		int m; cin >> m;
		while (m--) {
			int u, v; cin >> u >> v;
			cout << (find(u) == find(v) ? 1 : 0) << '\n';
		}

		cout << '\n';
	}

	return 0;
}