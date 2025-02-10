#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32005];
int ind[32005];

void topologicalSort() {
	vector<int> result;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		result.push_back(cur);
		for (int nxt : adj[cur])
			if (--ind[nxt] == 0) pq.push(nxt);
	}

	for (int e : result) cout << e << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		ind[b]++;
	}

	topologicalSort();
	return 0;
}