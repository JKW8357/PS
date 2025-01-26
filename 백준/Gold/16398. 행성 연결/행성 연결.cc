#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> adj;
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

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c; cin >> c;
			if (i != j) adj.push_back({ c, i, j });
		}
	}

	sort(adj.begin(), adj.end());
	int nodeCnt = (int)adj.size();

	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < nodeCnt; i++) {
		int a, b, c;
		tie(c, a, b) = adj[i];
		if (!unite(a, b)) continue;
		ans += c;
		cnt++;
		if (cnt == nodeCnt - 1) break;
	}

	cout << ans << '\n';
	return 0;
}