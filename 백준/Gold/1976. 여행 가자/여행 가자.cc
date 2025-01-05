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

	int n, m; cin >> n >> m;
	p.resize(n + 1);
	fill(p.begin(), p.end(), -1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int adj; cin >> adj;
			if (adj == 1) unionSets(i, j);
		}
	}
	
	vector<int> cities(m);
	bool flag = true;

	for (int i = 0; i < m; i++) cin >> cities[i];
	for (int i = 0; i < m - 1; i++) {
		if (find(cities[i]) != find(cities[i + 1])) {
			flag = false;
			break;
		}
	}

	cout << (flag ? "YES" : "NO") << '\n';
	return 0;
}