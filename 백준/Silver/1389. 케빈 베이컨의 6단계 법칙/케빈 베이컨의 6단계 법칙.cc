#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = INT_MAX;

vector<int> graph[105];
int dis[105];
int arr[105];

int bfs(int st) {
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	int sum = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (dis[nxt] != -1) continue;
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
			sum += dis[nxt];
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(dis + 1, dis + n + 1, -1);
		arr[i] = bfs(i);
	}

	cout << min_element(arr + 1, arr + n + 1) - arr << '\n';
	return 0;
}