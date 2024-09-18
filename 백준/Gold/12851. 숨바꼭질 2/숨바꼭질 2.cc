#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int dis[100005];
int cnt = 0;

int bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	dis[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) cnt++;

		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt > MX) continue;

			if (dis[nxt] == -1) {
				dis[nxt] = dis[cur] + 1;
				q.push(nxt);
			}

			else if (dis[nxt] == dis[cur] + 1) q.push(nxt);
		}
	}

	return dis[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	fill(dis, dis + MX + 1, -1);

	int ans = bfs(n, k);
	cout << ans << '\n' << cnt << '\n';

	return 0;
}