#include <bits/stdc++.h>
using namespace std;

int max_val = 0;
vector<int> graph[10005];
bool vis[10005];
int arr[10005];

int bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = true;
	int hacked = 1;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			hacked++;
			max_val = max(max_val, hacked);
		}
	}

	return hacked;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(vis + 1, vis + n + 1, false);
		arr[i] = bfs(i);
	}

	for (int i = 1; i <= n; i++) 
		if (arr[i] == max_val) cout << i << ' ';

	return 0;
}