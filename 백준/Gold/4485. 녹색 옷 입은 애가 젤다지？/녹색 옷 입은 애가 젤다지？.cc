#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t;

int n, m;
const int INF = (int)1e9;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> board;

int dijkstra() {
	priority_queue<t, vector<t>, greater<t>> pq;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	dist[1][1] = board[1][1];
	pq.push({ dist[1][1], 1, 1 });

	while (!pq.empty()) {
		auto [c, x, y] = pq.top(); pq.pop();
		if (dist[x][y] != c) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (dist[nx][ny] <= dist[x][y] + board[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + board[nx][ny];
			pq.push({ dist[nx][ny], nx, ny });
		}
	}

	return dist[n][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	while (++tc) {
		cin >> n;
		if (n == 0) break;
		board.assign(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> board[i][j];
		cout << "Problem " << tc << ": " << dijkstra() << '\n';
	}

	return 0;
}