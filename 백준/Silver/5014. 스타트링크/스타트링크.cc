#include <bits/stdc++.h>
using namespace std;

int floors, start, goal, up, down;
int dis[1000005];

int bfs() {
	queue<int> q;
	q.push(start);
	dis[start] = 0;

	int nxt;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == goal) return dis[cur];
		
		nxt = cur + up;
		if (nxt <= floors && dis[nxt] == -1) {
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
		}

		nxt = cur - down;
		if (nxt >= 1 && dis[nxt] == -1) {
			q.push(nxt);
			dis[nxt] = dis[cur] + 1;
		}
	}

	return -1; // 예외 처리 필수
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> floors >> start >> goal >> up >> down;
	fill(dis, dis + floors + 1, -1);
	int ans = bfs();

	if (ans != -1) cout << ans << '\n';
	else cout << "use the stairs\n";

	return 0;
}