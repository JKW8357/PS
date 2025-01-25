#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> adj[100005];
vector<int> p(10005, -1);

int find(int x) {
	if (p[x] == -1) return x;
	return p[x] = find(p[x]);
}

bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	p[y] = x;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[i] = { c, a, b };
	}

	sort(adj, adj + e);

	int cnt = 0, ans = 0;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		tie(c, a, b) = adj[i];
		if (!unite(a, b)) continue;
		ans += c;
		cnt++;
		if (cnt == v - 1) break;
	}

	cout << ans << '\n';
}