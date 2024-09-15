#include <bits/stdc++.h>
using namespace std;

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

	int n, m;
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

/*
최단 경로 문제에서는 DFS 대신 BFS나 다른 최단 경로 알고리즘을 이용하는 것이 효율적이다.
(DFS는 최단 경로를 보장하지 않는다.)
*/
