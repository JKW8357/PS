#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100005);
vector<vector<int>> reversedAdj(100005);
vector<bool> reachable_from_1(100005, false);
vector<bool> reachable_to_n(100005, false);

void bfs(int start, vector<bool>& canVisit, vector<vector<int>>& graph) {
	queue<int> q;
	q.push(start);
	canVisit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int nxt : graph[cur]) {
			if (canVisit[nxt]) continue;
			canVisit[nxt] = true;
			q.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		reversedAdj[v].push_back(u);
	}

	bfs(1, reachable_from_1, adj);
	bfs(n, reachable_to_n, reversedAdj);

	int t;
	cin >> t;
	while (t--) {
		int bomb; cin >> bomb;
		if (reachable_from_1[bomb] && reachable_to_n[bomb]) cout << "Defend the CTP\n";
		else cout << "Destroyed the CTP\n";
	}

	return 0;
}