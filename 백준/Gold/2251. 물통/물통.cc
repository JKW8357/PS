#include <bits/stdc++.h>
using namespace std;

int add;
set<int> ans;
bool vis[201][201][201];

void bfs(int ma, int mb, int mc) {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, mc });
	vis[0][0][mc] = true;

	while (!q.empty()) {
		auto [a, b, c] = q.front(); q.pop();
		if (a == 0) ans.insert(c);
		
		// a -> b
		add = min(a, mb - b);
		if (!vis[a - add][b + add][c]) {
			vis[a - add][b + add][c] = true;
			q.push({ a - add, b + add, c });
		}

		// b -> a
		add = min(ma - a, b);
		if (!vis[a + add][b - add][c]) {
			vis[a + add][b - add][c] = true;
			q.push({ a + add, b - add, c });
		}

		// a -> c
		add = min(a, mc - c);
		if (!vis[a - add][b][c + add]) {
			vis[a - add][b][c + add] = true;
			q.push({ a - add, b, c + add });
		}

		// c -> a
		add = min(ma - a, c);
		if (!vis[a + add][b][c - add]) {
			vis[a + add][b][c - add] = true;
			q.push({ a + add, b, c - add });
		}

		// b -> c
		add = min(b, mc - c);
		if (!vis[a][b - add][c + add]) {
			vis[a][b - add][c + add] = true;
			q.push({ a, b - add, c + add });
		}

		// c -> b
		add = min(mb - b, c);
		if (!vis[a][b + add][c - add]) {
			vis[a][b + add][c - add] = true;
			q.push({ a, b + add, c - add });
		}
	}

	for (int e : ans) cout << e << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	bfs(a, b, c);

	return 0;
}