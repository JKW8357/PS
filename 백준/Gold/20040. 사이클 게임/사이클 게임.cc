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

	int n, m;
	cin >> n >> m;
	p.assign(n, -1);

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		if (find(u) != find(v)) unionSets(u, v);
		else { ans = i; break; }
	}

	cout << ans << '\n';
	return 0;
}