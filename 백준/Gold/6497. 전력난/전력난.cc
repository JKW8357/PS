#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> adj[200005];
vector<int> p(200005, -1);

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

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		int sum = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[i] = { z, x, y };
			sum += z;
		}

		fill(p.begin(), p.begin() + n, -1);
		sort(adj, adj + m);

		int cnt = 0, turnOn = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			tie(z, x, y) = adj[i];
			if (!unite(x, y)) continue;
			turnOn += z;
			cnt++;
			if (cnt == n - 1) break;
		}

		int ans = sum - turnOn;
		cout << ans << '\n';
	}
	
	return 0;
}