#include <bits/stdc++.h>
using namespace std;

int n;
int board[1005];
int dis[1005];

int bfs() {
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == n - 1) return dis[cur];
		for (int i = 1; i <= board[cur]; i++) {
			int nxt = cur + i;
			if (nxt >= n || dis[nxt] != 0) continue;
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];
	int ans = bfs();
	cout << ans << '\n';
	
	return 0;
}